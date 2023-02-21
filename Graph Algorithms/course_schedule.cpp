#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    int indegree[n+1];
    for(int i=0;i<=n;i++){
        indegree[i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]+=1;
    }
    vector<int>ans;

    int visited[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }

    for(int i=1;i<=n;i++){
        if(indegree[i]==0 && visited[i]==0){
            visited[i]=1;
            stack<int>s;
            s.push(i);
            while (s.size()){
                int curr=s.top();
                s.pop();
                ans.push_back(curr);
                for(auto next : adj[curr]){
                    indegree[next]-=1;
                    if(indegree[next]==0 && visited[next]==0){
                        visited[next]=1;
                        s.push(next);
                    }
                }
            }
        }       
    }
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}