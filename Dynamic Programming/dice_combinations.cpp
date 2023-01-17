#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int j=1;j<=n;j++){
    for(int i=1;i<=6;i++){
        
            if(j-i>=0){
                dp[j]+=dp[j-i]%1000000007;
            }
        }
    }
    cout<<dp[n]%1000000007;
    // cout<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }





    return 0;
}