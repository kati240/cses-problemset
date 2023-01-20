#include<iostream>
using namespace std;

int fn(int target,int *dp){
    if(dp[target]!=0){
        return dp[target];
    }
    int x=target;
    int min=10000000;
    while (x>=1){
        int t=x%10;
        x/=10;
        if(t!=0){
            int ab=fn(target-t,dp);
            if(1+ab<min){
                min=1+ab;
            }
        }

    }
    dp[target]=min;
    return min;
    
}

int main(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    dp[0]=1;
    fn(n,dp);
    cout<<dp[n]-1;
    return 0;

}