#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// long long int  n,m;
// long long int  coins[100005];
// vector<long long int >edges[100005];
// vector<long long int >redges[100005];
// vector<long long int >v; // for storing nodes from dfs for kosaraju
// vector<long long int >graph[100005];
// long long int  visited[100005];
// long long int  SCC[100005];
// long long int  label=1;



// void dfs(long long int  a){
//     if(visited[a]){
//         return;
//     }
//     else{
//         visited[a]=1;
//         for(auto x :edges[a]){
//             dfs(x);
//         }
//         v.push_back(a);
//     }
// }

// void dfs2(long long int  a){
//     if(visited[a]){
//         return;
//     }
//     else{
//         visited[a]=1;
//         SCC[a]=label;
//         for(auto x :redges[a]){
//             dfs2(x);
//         }
//         // SCC[a]=label;
//     }
// }


// int  main(){
//     cin>>n>>m;
//     for(long long int  i=0;i<n;i++){
//         cin>>coins[i+1];
//     }
//     for(long long int  i=0;i<m;i++){
//         long long int  a,b;
//         cin>>a>>b;
//         edges[a].push_back(b);
//         redges[b].push_back(a);
//     }
//     // implement kosaraju
//     // dp for finding answer in condensed graph

//     for(long long int  i=1;i<=n;i++){
//         if(!visited[i]) dfs(i);
//     }
//     vector<long long int >components;

//     // reverse(v.begin(),v.end());
//     for(long long int  i=0;i<=n;i++){
//         visited[i]=0;
//     }
//     for(long long int  i=0;i<v.size();i++){
//         // cout<<v[i]<<" ";
//         if(!SCC[v[i]]){
//             dfs2(v[i]);
//             label+=1;
//             components.push_back(v[i]);
//         }
//     }

//     // condense this graph 
//     vector<long long int >condensed_graph[label];
//     vector<long long int >rcondensed_graph[label];
//     long long int  value_of_SCC[label];
//     for(long long int  i=0;i<label;i++){
//         value_of_SCC[i]=0;
//     }
//     for(long long int  i=1;i<=n;i++){
//         long long int  curr_label=SCC[i];
//         // cout<<SCC[i]<<" ";
//         value_of_SCC[curr_label]+=coins[i];
//         for(auto x:edges[i]){
//             if(SCC[i]!=SCC[x]){
//                 if(count(condensed_graph[SCC[i]].begin(),condensed_graph[SCC[i]].end(),SCC[x])==0){
//                     condensed_graph[SCC[i]].push_back(SCC[x]);
//                     rcondensed_graph[SCC[x]].push_back(SCC[i]);
//                 }
//             }
//         }
//     }

//     long long int  ans[label];
//     for(long long int  i=1;i<label;i++){
//         ans[i]=value_of_SCC[i];
//     }
//     for(long long int  i=1;i<label;i++){
//         long long int  val=ans[i];
//         for(auto x:rcondensed_graph[i]){
//             val= value_of_SCC[i]+ans[x] > val ? value_of_SCC[i]+ans[x] : val;
//         }
//     }
//     long long int  final_ans=0;
//     for(long long int  i=1;i<label;i++){
//         if(ans[i]>final_ans){
//             final_ans=ans[i];
//         }
//     }
//     cout<<final_ans;
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rsz resize

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define R0F(i, a) for (int i = (a)-1; i >= 0; i--)
#define ROF(i, a, b) for (int i = (b); i >= a; i--)
#define trav(a, x) for (auto &a : x)

/* SCC from BenQ */
struct SCC {
	int N;
	vector<vi> adj, radj;
	vi todo, comps, comp;
	vector<bool> vis;
	void init(int _N) {
		N = _N;
		adj.rsz(N), radj.rsz(N), comp = vi(N, -1), vis.rsz(N);
	}
	void ae(int x, int y) { adj[x].pb(y), radj[y].pb(x); }
	void dfs(int x) {
		vis[x] = 1;
		trav(y, adj[x]) if (!vis[y]) dfs(y);
		todo.pb(x);
	}
	void dfs2(int x, int v) {
		comp[x] = v;
		trav(y, radj[x]) if (comp[y] == -1) dfs2(y, v);
	}
	void gen(int _N) {  // fills allComp
		FOR(i, 1, _N) if (!vis[i]) dfs(i);
		reverse(all(todo));
		trav(x, todo) if (comp[x] == -1) {
			dfs2(x, x);
			comps.pb(x);
		}
	}
};

const int maxn = 1e5 + 5;

int n, m;
SCC scc;          // scc
int value[maxn];  // value of each room
ll group[maxn];   // value in each SCC
vi rgraph[maxn];  // reverse graph
ll dp[maxn];

// calculates dp[i]
ll DP(int i) {
	if (dp[i]) return dp[i];
	// start at i
	dp[i] = group[i];
	// simulate traveling from another SCC to this SCC
	trav(j, rgraph[i]) dp[i] = max(dp[i], DP(j) + group[i]);
	return dp[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	scc.init(n + 1);
	FOR(i, 1, n) cin >> value[i];
	while (m--) {
		int a, b;
		cin >> a >> b;
		scc.ae(a, b);
	}

	// generate SCC
	scc.gen(n);
	// set dp to 0
	fill(dp + 1, dp + n + 1, 0);
	// precompute group value for each SCC
	FOR(i, 1, n) group[scc.comp[i]] += value[i];
	// create reverse edges for SCC
	FOR(i, 1, n) trav(j, scc.adj[i]) {
		if (scc.comp[i] == scc.comp[j]) continue;
		rgraph[scc.comp[j]].pb(scc.comp[i]);
	}
	// find dp value for each SCC
	ll ans = 0;
	trav(i, scc.comps) ans = max(ans, DP(i));

	cout << ans << '\n';
}