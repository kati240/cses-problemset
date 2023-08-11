#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void build(long long int  seg_tree[], long long int  arr[],long long int  node, long long int  left,long long int  right){
    if(left==right){
        seg_tree[node]=arr[left-1];
        return ;
    }
    else{
        long long int  mid=(left+right)/2;
        build(seg_tree,arr,2*node, left,mid);
        build(seg_tree,arr,2*node+1,mid+1,right);
        seg_tree[node]=min(seg_tree[2*node],seg_tree[2*node+1]);
        return ;
    }
}
void update(long long int  seg_tree[], long long int  arr[],long long int  node, long long int  left,long long int  right, long long int  val, long long int  index){
    if(left==right && left==index){
        seg_tree[node]=val;
        arr[index-1]=val;
        return ;
    }
    else{
        long long int  mid=(left+right)/2;
        if(left<=index && index<=mid){
            update(seg_tree,arr,2*node, left,mid, val, index);
        }
        else{
            update(seg_tree,arr,2*node+1,mid+1,right, val, index);
        }
        seg_tree[node]=min(seg_tree[2*node],seg_tree[2*node+1]);
        return ;
    }
}

long long int  query(long long int  seg_tree[],long long int  node, long long int  start, long long int  end, long long int  l, long long int  r){
    if(r < start or end < l){
        return  9223372036854775807;
    }
    if(l <= start and end <= r){
        return seg_tree[node];
    }

    long long int  mid = (start + end) / 2;
    long long int  p1 = query(seg_tree,2*node, start, mid, l, r);
    long long int  p2 = query(seg_tree,2*node+1, mid+1, end, l, r);
    return min(p1 ,p2);
}

int  main(){
    long long int  n,q;
    cin>>n>>q;
    long long int  arr[n];
    for(long long int  i=0;i<n;i++){
        cin>>arr[i];
    }
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) -1 ;

    long long int  seg_tree[max_size];
    for(long long int i=0;i<max_size;i++){  
        seg_tree[i]= 9223372036854775807 ;
    }  
    build(seg_tree,arr,1,1,n);
    for(long long int i=0;i<q;i++){
        long long int  a,b;
        cin>>a>>b;
        cout<<query(seg_tree,1,1,n,a,b)<<endl;
    }

    return 0; 
}