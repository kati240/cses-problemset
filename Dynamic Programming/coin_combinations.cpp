#include<iostream>
using namespace std;

int main(){
    int n,target;

    cin>>n>>target;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    long long int dp[target+1];
    for(int i=0;i<=target;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int j=1;j<=target;j++){
        for(int i=0;i<n;i++){
            if(j-coins[i]>=0){
                dp[j]+=dp[j-coins[i]]%1000000007;
            }
        }
    }
    cout<<dp[target]%1000000007;
    return 0;
}