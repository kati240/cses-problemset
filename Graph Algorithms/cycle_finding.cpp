#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define INF 1e18

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > edges;
    vector<pair<int,int> >adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        vector<int>edge;
        edge.push_back(a);
        edge.push_back(b);
        edge.push_back(x);
        adj[a].push_back(make_pair(b,x));
        edges.push_back(edge);
    }
    long long int dist[n+1];
    long long int par[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=INF;
    }
    dist[1]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            int u=edges[j][0];
            int v=edges[j][1];
            int weight=edges[j][2];
            if(weight+dist[u]<dist[v]){
                dist[v]=dist[u]+weight;
                par[v]=u;
            }
        }
    }
    int change=0;
    int node=0;
    vector<int>changing_nodes;
    for(int i=0;i<1;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int weight=edges[j][2];
            if(weight+dist[u]<dist[v]){
                change=1;
                node=v;
            }
        }
    }
    if(change){
        cout<<"YES"<<endl;
        int f=node;
        vector<int> cyc;
        for(int i=0;i<=n;i++){// go back all t he way then start
             f = par[f];
        }
        
        for (int x = f;; x = par[x]){
            cyc.push_back(x);
            if (x==f && cyc.size()>1) break;
        }

        for(int i=0;i<cyc.size();i++){
            cout<<cyc[cyc.size()-1-i]<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}