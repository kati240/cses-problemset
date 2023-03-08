#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100000+1];
int rankarr[100000+1];

int findParent(int a){
    if(parent[a]==a){
        return a;
    }
    else{
        int x=findParent(parent[a]);
        parent[a]=x;
        return x;
    }
}

int Union(int a,int b){
    if(rankarr[a]<rankarr[b]){
        parent[a]=b;
    }
    else{
        parent[b]=a;
        if(rankarr[a]==rankarr[b]){
            rankarr[a]+=1;
        }
    }
    return 0;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int> > edges;
    for(int i=0;i<m;i++){
        int a,b,cost;
        vector<int>edge;
        cin>>a>>b>>cost;
        edge.push_back(cost);
        edge.push_back(a);
        edge.push_back(b);
        edges.push_back(edge);
    }
    for(int i=0;i<=n;i++){
        parent[i]=i;
        rankarr[i]=0;
    }
    sort(edges.begin(),edges.end());
    long long int ans=0;
    for(int i=0;i<m;i++){
        int a=edges[i][1];
        int b=edges[i][2];
        if(findParent(a)!=findParent(b)){
            a=findParent(a);
            b=findParent(b);
            Union(a,b);
            ans+=edges[i][0];
        }
    }
    int x=findParent(1);
    int flag=0;
    for(int i=1;i<=n;i++){
        if(findParent(i)!=x){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<ans<<endl;    
    }
    return 0;
}