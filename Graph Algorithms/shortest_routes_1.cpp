#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,len;
        cin>>a>>b>>len;
        adj[a].push_back(make_pair(b,len));
    }
    long long int dist[n+1];
    long long int processed[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=922337206854775807;
        processed[i]=0;
    }
    dist[1]=0;
    priority_queue<pair<long long int ,int> > q;
    q.push(make_pair(0,1));
    while (!q.empty())
    {
        int u=q.top().second;
         q.pop();
        if(processed[u]){
            continue;
        }
        processed[u]=1;
       
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int weight=adj[u][i].second;
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                q.push(make_pair(-dist[v],v)); // well, dijkstra involves heap too 
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}