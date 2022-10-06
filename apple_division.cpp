#include<iostream>
using namespace std;
long long int fn(int *arr,long long int currsum,long long int currsum2,int n){
    if(n==-1){
        return abs(currsum2 -currsum);
    }
    else{
        return min(fn(arr,currsum+arr[n],currsum2,       n-1),// make all combinations and check
                   fn(arr,currsum       ,currsum2+arr[n],n-1));
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    long long int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<fn(arr,0,0,n-1);
    return 0;
}