#include<iostream>
using namespace std;

long long int nc2(long long int a){
    return (a*(a-1)) /2;
}
int main(){
    int n;
    cin>>n;
    long long int count_remainder[n];
    for(long long int i=0;i<n;i++){
        count_remainder[i]=0;
    }
    long long int curr=0;
    long long int t;
    count_remainder[0]=1;
    
    for(long long int i=0;i<n;i++){
        cin>>t;
        curr+=t;
        curr=curr%n;
        count_remainder[(curr % n + n) % n]+=1;  // for negative results
       
    }
    long long int ans=0;
    for(long long int i=0;i<n;i++){
        ans+=nc2(count_remainder[i]);
    }
    
    cout<<ans;
    return 0;
}