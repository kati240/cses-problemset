#include<iostream>
#include<vector>

using namespace std;
#define pb push_back
using namespace std;
vector<int> G[100004];
int vis[100004];
vector<int> ans;
int s;
bool dfs(int u, int p, int pre){ 
    vis[u] = p;// here assign a faction
    for(int v : G[u]){
        if(vis[v]){
            if(vis[v] == p){// if it belongs to the same faction 
                s = v;
                ans.pb(v);
                ans.pb(u);
                return 1;
            }
            continue;
        }
        if(dfs(v, p, u)){// if not visited dfs again on curr node with u as just prev node 
            ans.pb(u);
            if(s == u){// if we reach the parent stop and print or recurse 
                cout << ans.size() << "\n";
                for(int a : ans){
                    cout << a << " ";
                }
                exit(0);
            }
            return 1;
        }
    }
    return 0;
}
signed main(){
    int n, m, a, b;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        // G[a].pb(b);
        G[b].pb(a);// just round trip 1 with 2 commented lines 
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ans.clear();
            dfs(i, i, 0);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}