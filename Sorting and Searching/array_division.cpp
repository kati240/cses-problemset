#include<iostream>
using namespace std;


int n,k;
bool isValid(long long int a, int *arr){
    int curr_divisions=0;
    long long int curr=0;
    for(int i=0;i<n;i++){
        if(arr[i]>a){
            return 0;
        }
        if(curr +arr[i]>a){
            curr=0;
            curr_divisions+=1;  
        }
        curr+=arr[i];
        if(curr_divisions>k){
            return 0;
        }
    }
    if(curr>0){
        curr_divisions+=1;
    }
    if(curr_divisions>k){
        return 0;
        }
    return 1;
}
int main(){
   
    cin>>n>>k;
    int arr[n];
    long long int sum=0;
    long long int max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
    }
    long long int left=0;
    long long int right=sum;
    long long int mid;
    long long int ans;
    while (left<=right)
    {   
        mid=(left+right)/2;
        if(isValid(mid,arr)){
            right=mid-1;
            ans=mid;
            
        }
        else{
            left=mid+1;
        }
    }
    cout<<ans;
    return 0;
}