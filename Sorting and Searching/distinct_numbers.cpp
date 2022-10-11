#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<int>a;
    cin>>n;

    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }

    sort(a.begin(),a.end());
    int ans=1;
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]){
            ans+=1;
        }
    }
    cout<<ans;

}