#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    if (sum%2) {
        cout << 0 << endl;
        return 0;
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=0;
        }
    }
    dp[1][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];// dont take
            if(j>=i){
                dp[i][j]+=dp[i-1][j-i]; // take 
            }
            dp[i][j]%=1000000007;
        }
      
    }
    cout<<dp[n][sum/2];
    return 0;
}