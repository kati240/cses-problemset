#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
// int n,m,a,b;
// char signs[2];


// vector<int> edges[200005];
// vector<int> redges[200005];
// int visited[200005];
// vector<int>v;



// int dfs(int a){
//     if(visited[a]) return 0;
//     else{
//         visited[a]=1;
//         for(auto x:edges[a]){
//             dfs(x);
//         }
//         v.push_back(a);
//         return 0;
//     }
// }



// int transform(int x){
//     if(x<=m) return x+m;
//     else return x-m;
// }

// int main(){
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         cin>>signs[0]>>a>>signs[1]>>b;

//         if(signs[0]=='+') a+=m;
//         if(signs[1]=='+') b+=m;

//         edges[transform(a)].push_back(b);
//         edges[transform(b)].push_back(a);
//         redges[b].push_back(transform(a));
//         redges[a].push_back(transform(b));
//     }
//     for(int i=0;i<200005;i++){
//         if(!visited[i]) dfs(i);
//     }
//     reverse(v.begin(),v.end());
//     // do reverse dfs for members of vector v and assign SCCs and values for i and m+i;
   



// }




using namespace std;

struct two_sat {
    int n;
    vector<vector<int>> g, gr;
    vector<int> comp, topological_order, answer;
    vector<bool> vis;

    two_sat() {}

    two_sat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }

    void dfs(int u) {
        vis[u] = true;

        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);

        topological_order.push_back(u);
    }

    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;

        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }

    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto &v : topological_order)
            if (!vis[v]) scc(v, id++);

        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};

signed main() {
    int N, M;
    cin >> N >> M;

    two_sat solver(M);

    while (N--) {
        int topping1, topping2;
        char preference1, preference2;
        cin >> preference1 >> topping1 >> preference2 >> topping2;

        solver.add_clause_or(topping1 - 1, preference1 == '+', topping2 - 1, preference2 == '+');
    }

    if (!solver.satisfiable()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 0; i < M; i++)
        cout << (solver.answer[i] ? '+' : '-') << " ";
}




