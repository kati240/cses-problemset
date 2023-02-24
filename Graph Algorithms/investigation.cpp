#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair< int,long long int> >adj[n+1];
    for(int i=0;i<m;i++){
        long long int a,b,x;
        cin>>a>>b>>x;
        adj[a].push_back(make_pair(b,x));
    }
    priority_queue<pair<long long int , int>, vector<pair<long long , int> >, greater<pair<long long int , int> > > pq;
    long long int dist[n+1];
    long long int ways[n+1];
    int min_flights[n+1];
    int max_flights[n+1];
    int visited[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=1000000000000000000;
    }
    
    memset(ways, 0, (n+1) * sizeof(long long int));
    memset(min_flights, 0, (n+1) * sizeof(int));
    memset(max_flights, 0, (n+1) * sizeof(int));
    memset(visited, 0, (n+1) * sizeof(int));

    pq.push(make_pair(0,1));
    ways[1]=1;
    dist[1]=0;
    while (pq.size()){
        int curr=pq.top().second;
        pq.pop();
        if(!visited[curr]){
            visited[curr]=1;
            for(int i=0;i<adj[curr].size();i++){
                pair<long long int ,int > x=adj[curr][i];
                int next=x.first;
                long long int weight=x.second;
                long long int distance=dist[curr]+weight;
                if(distance<dist[next]){
                    ways[next]=ways[curr];
                    ways[next]%=1000000007;
                    min_flights[next]=1+min_flights[curr];
                    max_flights[next]=1+max_flights[curr];
                    dist[next]=distance;
                    pq.push(make_pair(distance,next));
                }
                else if(distance==dist[next]){
                    ways[next]+=ways[curr];
                    ways[next]%=1000000007;
                    min_flights[next]=min(min_flights[next],min_flights[curr]+1);
                    max_flights[next]=max(max_flights[next],max_flights[curr]+1);
                }
            }
        }
    }

    cout<< dist[n]<<" "<<ways[n]<<" "<<min_flights[n]<<" "<<max_flights[n];
    return 0;
}