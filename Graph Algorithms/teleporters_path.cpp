#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    set<int>edges[n+1];
    set<int>edges_copy[n+1];
    int indegree[n+1];
    for(int i=0;i<=n;i++){
        indegree[i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].insert(b);
        edges_copy[a].insert(b);
        // edges[b].insert(a);
        indegree[a]-=1;
        indegree[b]+=1;
    }
    int odd_indegree=0;
    for(int i=0;i<=n;i++){
        if(indegree[i]%2){
            odd_indegree+=1;
            if(odd_indegree>2){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    if(odd_indegree==1){
        cout<<"IMPOSSIBLE";
        return 0;
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
            edges[curr].erase(v);
            st.push(v);
        }
    }
    if(ans.size()!=m+1 || ans[0]!=n){
        cout<<"IMPOSSIBLE";
    }
    else{
        int flag=0;
        int prev=1;

        for(int i=ans.size()-2;i>=0;i--){
            if(edges_copy[prev].find(ans[i])!=edges_copy[prev].end()){
                prev=ans[i];
                continue;
            }
            else{
                flag=1;
                break;
            }
        }




        if(flag==0){
            for(int i=ans.size()-1;i>=0;i--){
                cout<<ans[i]<<" ";
            }
        }
        else{
            cout<<"IMPOSSIBLE";
        }
        
    }
    
    return 0;
}