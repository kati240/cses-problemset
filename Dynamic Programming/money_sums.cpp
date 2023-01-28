#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int dp[sum+1];
    for(int i=0;i<=sum;i++){
        dp[i]=0;
    }
    dp[0]=1;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=sum;j>=arr[i];j--){
            if(dp[j-arr[i]]==1){
                if(dp[j]==0){
                    ans+=1;
                }
                dp[j]=1;
            }

        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=sum;i++){
        if(dp[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}