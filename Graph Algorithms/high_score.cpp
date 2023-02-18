#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
 
#define INF  1e18;
 
 
int main(){

    long long  int n,m;
    cin>>n>>m;
    vector<pair<int,int> > adj[n+1];
    vector<vector<int> > edges;
 
    for(long long int i=0;i<m;i++){
        long long  int a,b,x;
        cin>>a>>b>>x;
        vector<int> edge;
        edge.push_back(a);
        edge.push_back(b);
        edge.push_back(x);
        edges.push_back(edge);
        adj[a].push_back(make_pair(b,x));
    }
    long long int dist[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=INF;
    }
    dist[1]=0;
 
    for(int i=0;i<n-1;i++){
        for(auto edge :edges){
            int u=edge[0];
            int v=edge[1];
            int weight=edge[2];
            if(dist[v]>dist[u]-weight){
                dist[v]=dist[u]-weight;
            }
        }
    }
    int changed=0;
    vector<int>cycle_belonging_nodes;
    for(int i=0;i<1;i++){
        for(auto edge :edges){
            int u=edge[0];
            int v=edge[1];
            int weight=edge[2];
            if(dist[v]>dist[u]-weight){
                dist[v]=dist[u]-weight;
                cycle_belonging_nodes.push_back(v);
                
            }
        }
    }

    int flag=0;
    set<int>possible_points;
    for(int i=0;i<cycle_belonging_nodes.size();i++){
        int curr=cycle_belonging_nodes[i];
        // dfs from this node to check if i can reach node n
        int visited[n+1];
        stack<int> s;
        s.push(curr);
        for(int j=0;j<=n;j++){
            visited[j]=0;
        }
        while (s.size()){
            int curr=s.top();
            s.pop();
            if(curr==n){
                possible_points.insert(cycle_belonging_nodes[i]);
                break;
            }
            if(visited[curr]==0){
                visited[curr]=1;
                for(auto x :adj[curr]){
                    s.push(x.first);
                }
            }
        }
        if (flag){
            break;
        }
    }

    for(int i=0;i<1;i++){
        int curr=1;
        // dfs from 1  to check if i can reach nodes that form cycle and can end in n
        int visited[n+1];
        stack<int> s;
        s.push(curr);
        for(int i=0;i<=n;i++){
            visited[i]=0;
        }
        while (s.size()){
            int curr=s.top();
            s.pop();
            if(possible_points.find(curr)!=possible_points.end()){
                flag=1;
                changed=1;
                break;
            }
            if(visited[curr]==0){
                visited[curr]=1;
                for(auto x :adj[curr]){
                    s.push(x.first);
                }
            }
        }
        if (flag){
            break;
        }
    }
    if(!changed){
        cout<<-1*dist[n];
    }
    else{
        cout<<-1;
    }
    return 0;
}