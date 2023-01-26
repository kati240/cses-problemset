#include<iostream>
#include<vector>
using namespace std;

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int n,m;
    n=a.length();
    m=b.length();
    int dp[n+1][m+1]; // dp[i][j]=ways of making a[i] = b[j]
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=1000000000;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if (i) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);// intial setup
                }
            if (j) {
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
            if (i && j) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1] != b[j-1]));// checking for equal condition 
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}