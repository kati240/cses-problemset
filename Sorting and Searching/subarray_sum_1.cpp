#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    long long int curr=0; 
    set<long long int>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        curr+=arr[i];
        s.insert(curr);
    }
    int ans=0;
    curr=0;
    if(s.find(curr+target)!=s.end()){
            ans+=1;
    }

    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(s.find(curr+target)!=s.end()){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}