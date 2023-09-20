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
    seg_tree[node]=0;
}
void update(long long int  seg_tree[], long long int  arr[],long long int  node, long long int  left,long long int  right, long long int  val, long long int  index){
    if(left==right){
        seg_tree[node]+=val;
        arr[index-1]+=val;
        return ;
    }
    else{
        long long int  mid=(left+right)/2;
        if(index<=mid){
            update(seg_tree,arr,2*node, left,mid, val, index);
        }
        else{
            update(seg_tree,arr,2*node+1,mid+1,right, val, index);
        }
        seg_tree[node]=(seg_tree[2*node] + seg_tree[2*node+1]);
        return ;
    }
}

long long int  query(long long int  seg_tree[],long long int  node, long long int  start, long long int  end, long long int  l, long long int  r){
    if(r < start ||  end < l){
        return  0;
    }
    if(l <= start and end <= r){
        return seg_tree[node];
    }

    long long int  mid = (start + end) / 2;
    long long int  p1 = query(seg_tree,2*node, start, mid, l, r);
    long long int  p2 = query(seg_tree,2*node+1, mid+1, end, l, r);
    return p1 + p2;
}

int main(){
    int n,q;
    cin>>n>>q;
    long long int arr[n];
    long long int updateArr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        updateArr[i]=0;
    }

    int x = (int)ceil(log2(n));
    int size = 2*pow(2,x) -1;
    long long seg_tree[size];
    build(1,1,n,updateArr,seg_tree);
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            long long int left,right,val;
            cin>>left>>right>>val;
            update(seg_tree,updateArr,1,1,n,val,left);
            if(right!=n){
                update(seg_tree,updateArr,1,1,n,-val,right+1);
            }  
        }
        else{
            int index;
            cin>>index;
            long long add=query(seg_tree,1,1,n,1,index);
            long long ans=arr[index-1] + add;
            cout<<ans<<endl;
        }
    }

    return 0;
}