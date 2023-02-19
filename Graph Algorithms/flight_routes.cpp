#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int> > adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        adj[a].push_back(make_pair(b,x));
    }
    int visited[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }
    priority_queue<pair<long long int,int > > pq;
    pq.push(make_pair(0,1));
    vector<long long int> v;
    while (pq.size() && visited[n]<k)
    {
        pair<long long int,int>  curr;
        curr=pq.top();
        pq.pop();
        visited[curr.second]++;
        if(curr.second==n){
            v.push_back(-1 *curr.first);
        }

        if(visited[curr.second]<=k){// modify djikstra to visit a particular node max k times 
            for(auto edge: adj[curr.second]){
                pq.push(make_pair(-1 *(edge.second+ -1 * curr.first ), edge.first));
            }

        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}