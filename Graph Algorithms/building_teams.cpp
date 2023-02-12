#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int groups[n+1];
    for(int i=0;i<=n;i++){
        groups[i]=0;
    }
    int a ,b;
    vector<int> adj[n+1];
    int flag=0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(adj[i].size()){
            if(groups[i]==0){
                q.push(i);
                while (q.size())
                {
                    int curr=q.front();
                    int curr_group;
                    if(groups[curr]==0){
                        curr_group=1;
                    }
                    else{
                        curr_group=groups[curr];
                    }
                    q.pop();
                    for(int j=0;j<adj[curr].size();j++){
                        
                        if(groups[adj[curr][j]]==0){
                            q.push(adj[curr][j]);
                            groups[adj[curr][j]]=3-curr_group;
                        }
                        else if(groups[adj[curr][j]]+curr_group !=3){
                            flag=1;
                            break;
                        }
                    }
                }
            }    
        }
        else{
            groups[i]=1;
        }
    }
    if(flag==0){
        for(int i=1;i<=n;i++){
            cout<<groups[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}