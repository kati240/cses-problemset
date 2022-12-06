#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long int arr[n];
    long long int total=0;
    long long int ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
    }
    sort(arr,arr+n);
    if(2*arr[n-1]>total){
        ans=2*arr[n-1];
    }
    else{
        ans=total;
    }
    cout<<ans;
    return 0;
}