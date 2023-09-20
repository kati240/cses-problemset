#include<iostream>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int mat[n][n];
    int dp[n][n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            s[j] =='*' ?  mat[i][j]=1 : mat[i][j]=0;
            dp[i][j]=mat[i][j];
        }
    }
    for(int i=1;i<n;i++){
        dp[i][0]+=dp[i-1][0];
        dp[0][i]+=dp[0][i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]+= dp[i-1][j]+ dp[i][j-1] -dp[i-1][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int top, left, bot ,right;
        cin>>top>>left>>bot>>right;
        top-=1;
        left-=1;
        bot-=1;
        right-=1;
        int ans=0;
        ans+=dp[bot][right];
        if(left>0){
            ans-=dp[bot][left-1];
        }
        if(top>0){
            ans-=dp[top-1][right];
        }
        if(top>0 && left>0){
            ans+=dp[top-1][left-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}