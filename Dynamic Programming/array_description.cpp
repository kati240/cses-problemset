#include<iostream>
using namespace std;

 int  main(){
    long long int  n,m;
    cin>>n>>m;
    long long int  arr[n];
    for (long long int  i = 0; i < n; i++){
        cin>>arr[i];
    }
    long long int  dp[n][m+1];// dp[i][x] = ax num. of ways to fill arr upto i if arr[i]=x
    for(long long int  i=0;i<n;i++){
        for(long long int  j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    if(arr[0]==0){
        for(long long int  i=0;i<=m;i++){
            dp[0][i]=1;
        }
    }
    else{
        dp[0][arr[0]]=1;
    }
    for (long long int  i = 1; i < n; i++) {
        if(arr[i] == 0) {
            for (long long int  j = 1; j <= m; j++) {
                dp[i][j] += dp[i-1][j];
                if(j - 1 > 0) dp[i][j] += dp[i-1][j-1];
                if(j + 1 <= m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= 1000000007;
            }
        } else {
            dp[i][arr[i]] += dp[i-1][arr[i]];
            if(arr[i] - 1 > 0) dp[i][arr[i]] += dp[i-1][arr[i]-1];
            if(arr[i] + 1 <= m) dp[i][arr[i]] += dp[i-1][arr[i]+1];
            dp[i][arr[i]] %= 1000000007;
        }
    }

    long long int  ans=0;

    for (long long int  i = 1; i <= m; i++) {
        ans += dp[n-1][i];
        ans %= 1000000007;
	}
    cout<<ans;
    return 0;
}