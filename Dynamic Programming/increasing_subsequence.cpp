#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        auto it=lower_bound(dp.begin(),dp.end(),arr[i]);
        if(it==dp.end()){
            dp.push_back(arr[i]);// dp[x]= the ending value of an incresing subsequence , push a value when you cant alrrady fit it
        }
        else{
            *it=arr[i];
        }
    }
    cout<<dp.size();
    

    return 0;
}
