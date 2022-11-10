#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,bool>m;
    int ans=0;
    int curr=0;
    int j=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(m.find(arr[i])==m.end() || m[arr[i]]==false){
            curr+=1;
            m[arr[i]]=true;
            ans=max(curr,ans);
        }
        else{
            while(arr[j]!=arr[i]){
                m[arr[j]]=false;
                
                j+=1;
            }
           
            curr=(i-j);
             j+=1;

        }
    }
    cout<<ans;
    return 0;
}