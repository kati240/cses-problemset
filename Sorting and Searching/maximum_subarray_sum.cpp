#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int ans=arr[0];
    if(n==1){
        cout<<ans;
    }
    else{
        long long int max_till_now=arr[0]; // kadane's algorithm
        for(int i=1;i<n;i++){
            if(max_till_now<0){
                max_till_now=max_till_now>arr[i]? max_till_now: arr[i];
            }
            else{
                max_till_now+=arr[i];
        
            }
            if(max_till_now>ans){
                ans=max_till_now;
            }
        }
        cout<<ans;
    }
    
    

    return 0;
}