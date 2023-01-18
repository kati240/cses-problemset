#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,target;
    cin>>n>>target;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    long long int ans[target+1];
    for(int i=0;i<=target;i++){
        ans[i]=100000000000;
    }
    ans[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=target;j++){
            if(j+coins[i]<=target){
                if(1+ans[j]<ans[j+coins[i]]){
                    ans[j+coins[i]]=1+ans[j];
                }
            }
        }
    }
    if(ans[target]!=100000000000){
        cout<<ans[target];
    }
    else{
        cout<<-1;
    }
    






    return 0;
}