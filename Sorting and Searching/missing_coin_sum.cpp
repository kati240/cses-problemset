#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long int ans=1;
    for(int i=0;i<n;i++){
        if(arr[i]<=ans){
            ans+=arr[i];
        }
        else{
            break;
        }
    }

    cout<<ans;


    return 0;
}