#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>edges[n+1];
    vector<int>redges[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        redges[b].push_back(a);
    }
    int visited[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }
    queue<int>q;

    q.push(1);
    while (q.size()){
        int curr=q.front();
        q.pop();
        if(visited[curr]==0){
            visited[curr]+=1;
            for(auto x : edges[curr]){
                q.push(x);
            }
        }
    }

    q.push(1);
    while (q.size()){
        int curr=q.front();
        q.pop();
        if(visited[curr]==1){
            visited[curr]+=2;
            for(auto x : redges[curr]){
                q.push(x);
            }
        }
    }
    int flag=0;
    int node=0;
    int node2=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==0 || visited[i]==1){
            flag+=1;
            if(flag==1){
                  node=i;
            }
            if(flag==2){
                node2=i;
                break;
            }
        }
    }
    if(flag==0){
        cout<<"YES";
    }
    else{
        if(visited[node]==1){
            cout<<"NO"<<endl<<node<<" "<<1;
        }
        else{
            cout<<"NO"<<endl<<1<<" "<<node<<endl;
        }
    }

    return 0;
}