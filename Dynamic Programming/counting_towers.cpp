#include<iostream>
using namespace std;

 int main(){
    long long int dp[1000001][2];
    for(int i=0;i<=1000000;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    // dp[i][0] if top is split
    // dp[i][1] if top is connected
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<=1000000;i++){
        dp[i][0]=(4*dp[i-1][0] + dp[i-1][1])% 1000000007;
        dp[i][1]=(2*dp[i-1][1]+ dp[i-1][0])% 1000000007;
    }
     int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        long long int ans=(dp[n-1][0]+ dp[n-1][1])%1000000007;
        cout<< ans<<endl;
    }
    return 0;
}