#include<iostream>
#include<set>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    int type[n+1];// 1 for cyclic 2 for connecting 
    int teleporter[n+1];
    int dist[n+1]; // forcyclic nodes this has size of cycle , for others this has dist to the connecting node
    int connecting_node[n+1];
    teleporter[0]=0;
    type[0]=0;
    dist[0]=0;
    connecting_node[0]=0;
    vector<int > radj[n+1];
    for(int i=0;i<n;i++){
        cin>>teleporter[i+1];
        radj[teleporter[i+1]].push_back(i+1);
        type[i+1]=0;
        dist[i+1]=0;
        connecting_node[i+1]=0;
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==0){
            set<int>s;
            stack<int> st;
            st.push(i);
            int flag=0;
            int node;
            while (flag==0){
                int curr=st.top();
                st.pop();
                if(s.find(curr)!=s.end()){
                    flag=1;
                    node=curr;
                }
                else{
                    st.push(teleporter[curr]);
                    s.insert(curr);
                }
            }
            int distance=1;
            vector<int>temp;
            temp.push_back(node);
            int curr=teleporter[node];
            while (curr!=node)
            {
                distance+=1;
                temp.push_back(curr);
                curr=teleporter[curr];
            }
            for(int j=0;j<temp.size();j++){
                dist[temp[j]]=distance;
            }
            for(int j=0;j<temp.size();j++){
                int new_dist=0;
                queue<int>q;
                for(auto x: radj[temp[j]]){
                    if(dist[x]==0){
                        q.push(x);
                    }
                }
                while (q.size())
                {
                    queue<int> new_q;
                    int l=q.size();
                    new_dist+=1;
                    for(int k=0;k<l;k++){
                        int curr=q.front();
                        q.pop();
                        connecting_node[curr]=temp[j];
                        dist[curr]=new_dist;
                        for(auto new_x:radj[curr]){
                            if(dist[new_x]==0){
                                new_q.push(new_x);
                            }
                        }
                    }
                    while(new_q.size()){
                        int abcd=new_q.front();
                        new_q.pop();
                        q.push(abcd);
                    }
                }   
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(connecting_node[i]==0){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<dist[i]+dist[connecting_node[i]]<<" ";
        }
    }
    return 0;
}