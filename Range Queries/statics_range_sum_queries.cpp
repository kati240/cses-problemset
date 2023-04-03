#include<iostream>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int prefix_sum[n+1];
    long long int curr=0;
    prefix_sum[0]=0;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        prefix_sum[i+1]=curr;
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<prefix_sum[b]-prefix_sum[a-1]<<endl;
    }
    return 0;
}