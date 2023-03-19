#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    set<int>edges[n+1];
    int indegree[n+1];
    for(int i=0;i<=n;i++){
        indegree[i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].insert(b);
        edges[b].insert(a);
        indegree[a]+=1;
        indegree[b]+=1;
    }
    for(int i=0;i<=n;i++){
        if(indegree[i]%2){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    int curr=1;
    int count=0;
    vector<int>ans;
    stack<int>st;
    st.push(1);
    while(st.size()){ // can't engineer luck 
        int curr=st.top();
        if(edges[curr].size()==0){
            st.pop();
            ans.push_back(curr);
        }
        else{
            int v=*edges[curr].begin();
            edges[v].erase(curr);
            edges[curr].erase(v);
            st.push(v);
        }
    }
    if(ans.size()!=m+1){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    
    return 0;
}