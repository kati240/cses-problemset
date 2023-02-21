#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int previous_node[n+1];
    for(int i=0;i<=n;i++){
        previous_node[i]=0;
    }
    int dist[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=0;
    }
    stack<int>s;
    s.push(1);
    while (s.size()){
        int curr=s.top();
        s.pop();
        for(auto next : adj[curr]){
            if(dist[curr]+1>dist[next]){
                previous_node[next]=curr;
                dist[next]=1+dist[curr];
                s.push(next);
            }
        }
    }
    if(dist[n]!=0){
        cout<<dist[n]+1<<endl;
        int curr=n;

        vector<int>ans;
        while (curr!=1)
        {
            ans.push_back(curr);
            curr=previous_node[curr];
        }
        ans.push_back(curr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[ans.size()-i-1]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}