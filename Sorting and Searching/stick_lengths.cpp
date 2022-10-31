#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int ans=0;
    sort(arr,arr+n);
    long long int median=arr[n/2]; // minimize sum of mods not same as minimizing the sum of squares
    for(int i=0;i<n;i++){
        ans+=abs(arr[i]-median);
    }
    cout<<ans;
    return 0;
}