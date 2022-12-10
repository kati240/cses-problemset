#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    long long int curr=0; 
    map<long long ,int>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        curr+=arr[i];
    }
    long long int ans=0;
    curr=0;
    m[0]=1;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        ans+=m[curr-target];
        m[curr]+=1;
    }
    cout<<ans;
    return 0;
}