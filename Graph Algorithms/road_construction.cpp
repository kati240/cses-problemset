#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int count_components=n;
    int parent[n+1];
    int rank[n+1];
    int size[n+1];
    for(int i=0;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
        size[i]=1;
    }
    int max_rank=1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        stack<int>s;
        s.push(a);
        int parent1=0;
        while (s.size()){
            if(parent1==0){
                int x=s.top();
                if(parent[x]==x){
                    parent1=x;
                }
                else{
                    s.push(parent[x]);
                }
            }
            else{
                int curr=s.top();
                s.pop();
                parent[curr]=parent1;
            }
        }
        s.push(b);
        int parent2=0;
        while (s.size()){
            if(parent2==0){
                int x=s.top();
                if(parent[x]==x){
                    parent2=x;
                }
                else{
                    s.push(parent[x]);
                }
            }
            else{
                int curr=s.top();
                s.pop();
                parent[curr]=parent2;
            }
        }
        if(parent1!=parent2){
            if(rank[parent1]<rank[parent2]){
                parent[parent1]=parent2;
                size[parent2]+=size[parent1];
                if(size[parent2]>max_rank){
                    max_rank=size[parent2];
                }
            }
            else{
                parent[parent2]=parent1;
                if(rank[parent1]==rank[parent2]){
                    rank[parent1]+=1;
                }
                size[parent1]+=size[parent2];
                if(size[parent1]>max_rank){
                    max_rank=size[parent1];
                }
            }
            count_components-=1;
        }
        cout<<count_components << " "<<max_rank <<endl;
    }
    return 0;
}