#include<iostream>
#include<cmath>

using namespace std;


void build(long long int node,long long int left,long long int right,long long int arr[] , long long int* seg_tree){
    if(left==right){
        seg_tree[node]=arr[left-1];
        return ;
    }
    int mid=(left+right) >>1;
    build(2*node , left, mid, arr,seg_tree);
    build(2*node + 1 , mid+1, right, arr,seg_tree);
    seg_tree[node]=max(seg_tree[2*node],seg_tree[2*node + 1]);
    return ;
}
void update(long long int  seg_tree[],long long int  node, long long int  left,long long int  right, long long int  val, long long int  index){
    if(left==right){
        seg_tree[node]-=val;
        return ;
    }
    else{
        long long int  mid=(left+right)/2;
        if(index<=mid){
            update(seg_tree,2*node, left,mid, val, index);
        }
        else{
            update(seg_tree,2*node+1,mid+1,right, val, index);
        }
        seg_tree[node]=max(seg_tree[2*node],seg_tree[2*node+1]);
        return ;
    }
}
long long int  query(long long int  seg_tree[],long long int  node, long long int  val, long long int  l, long long int  r, long long int n){

    if(l==r){
        update(seg_tree,1,1,n,val,l);
        return l;
    }
    long long int  mid = (l + r) / 2;
    if(seg_tree[2*node]>=val){
        return query(seg_tree,2*node,val,l,mid,n);
    }
    else{
        return query(seg_tree,2*node+1,val, mid+1, r, n);

    }
}


int main(){

    long long int n,m;
    cin>>n>>m;
    long long int hotels[n];
    for(int i=0;i<n;i++){
        cin>>hotels[i];
    }
    int x = (int)ceil(log2(n));
    int size = 2*pow(2,x) -1;
    long long seg_tree[size];
    build(1,1,n,hotels,seg_tree);

    for(int i=0;i<m;i++){
        int group;
        cin>>group;
        if(seg_tree[1]<group){
            cout<<0<<endl;
        }
        else{
            int index=query(seg_tree,1,group,1,n,n);
            cout<<index<<endl;
        }
    }
    
    return 0;
}