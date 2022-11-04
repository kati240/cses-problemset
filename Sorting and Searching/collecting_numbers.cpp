#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int seen[n+1]={0};

    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            ans+=1;
            seen[1]=1;
        }
        else{
            if(seen[arr[i]-1]==0){
                ans+=1;
            }
            seen[arr[i]]=1;

        }
        
    }
    cout<<ans;
    return 0;
}