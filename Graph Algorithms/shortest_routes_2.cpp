#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 9223372036854775807


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    long long int adj[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=INF;
        }
    }
    long long int dist[n+1][n+1];
    for(int i=0;i<m;i++){
        int a,b,len;
        cin>>a>>b>>len;
        if(len<adj[a][b]){
            adj[a][b]=len;
            adj[b][a]=len;
        }
      
    }
    vector<pair<int,int> >queries;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        queries.push_back(make_pair(a,b));
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else if (adj[i][j]!=INF){
                dist[i][j]=adj[i][j];
            }
            else{
                dist[i][j]=INF;
            }
        }
    }
    for(int k=1;k<=n;k++){// floyd-warshall to the rescue
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
               
            }
        }
    }
    for(int i=0;i<q;i++){
        if(dist[queries[i].first][queries[i].second]== INF){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[queries[i].first][queries[i].second]<<endl;
        }
    }
    return 0;
}
