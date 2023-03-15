#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int vis[100005];
int ans[100005];
vector<int>edges[100005];
vector<int>redges[100005];
stack<int>s;
int label=1;

void dfs(int a ){
    if(vis[a]==0){
        vis[a]=2;
        for(auto x:edges[a]){
            dfs(x);
        }
        s.push(a);
    }
}

void dfs2(int a ){
    if(vis[a]==0){
        vis[a]=1;
        for(auto x:redges[a]){
            dfs2(x);
        }
        ans[a]=label;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        redges[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }

    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    while (s.size())
    {
        int curr=s.top();
        s.pop();
        if(ans[curr]==0){
            dfs2(curr);
            label+=1;
        }
        
    }
    cout<<label-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

