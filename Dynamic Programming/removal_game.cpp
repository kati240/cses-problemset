#include<iostream>
using namespace std;

 int  main(){
    long long int  n;
    cin>>n;
    long long int  sum=0;
    long long int  arr[n];
    for(long long int  i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    long long int  dp[n][n];
    for(long long int  left=n-1;left>=0;left--){
        for(long long int  right=left;right<n;right++){
            if(left==right){
                dp[left][right]=arr[left];
            }
            else{
                dp[left][right]=max(arr[left]-dp[left+1][right],-1*dp[left][right-1]+arr[right]); // dp[l][r]=s1-s2 for l...r
            }
        }
    }
    cout<<(dp[0][n-1]+sum) /2;
    return 0;
}