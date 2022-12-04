#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > tasks;
    int a,d;
    for(int i=0;i<n;i++){
        cin>>a>>d;
        tasks.push_back(make_pair(a,d));
    }
    sort(tasks.begin(),tasks.end()); // yeah , just process in shortest duration
    long long int ans=0;
    long long int curr=0;
    pair<int,int>t;
    for(int i=0;i<n;i++){
        t=tasks[i];
        curr+=t.first;
        ans+=t.second-curr;
    }
    cout<<ans;




    return 0;
}