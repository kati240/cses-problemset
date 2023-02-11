#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=1e5;
vector<int>adj[N+1];
vector<bool> visited(N+1, false);
int last_visited[N+1];

// int bfs(int end){     // does not work 
//     queue<int> q;
//     q.push(1);
//     while (q.size()!=0){
//         int curr=q.front();
//         q.pop();
//         if(end==curr){
//             cout<<"fdbsfaab";
//             return 1;
//         }
//         if(!visited[curr]){
//             visited[curr]=true;
//             for (int i = 0; i < adj[curr].size(); i++)
//             {
//                 if(visited[adj[curr][i]]==false){
//                     q.push(adj[curr][i]);
//                 }
//                 last_visited[adj[curr][i]]=curr;
//             }
//         }
//     }
//     return 0;
// }

int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<=N;i++){
        last_visited[i]=0;
    }
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){  // this does work
        int u = Q.front(); Q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                last_visited[v] = u;
                Q.push(v);
            }
        }
    }
    if(visited[n]){
        int count=0;
        vector<int> ans;
        int curr=n;
        while (curr!=1){
            ans.push_back(curr);
            count+=1;
            curr=last_visited[curr];
        }
        count+=1;
        ans.push_back(1);
        cout<<count<<endl;
        for(int i=count-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }  
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
    return 0;
}