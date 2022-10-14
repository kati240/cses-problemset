#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > times;
    int a;
    int b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        times.push_back(std::make_pair(a,b));
    }
    sort(times.begin(),times.end());
    priority_queue <int, vector<int>, greater<int> > pq;
    int curr=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(i!=0){
            while(!pq.empty() && pq.top()<times[i].first){
                pq.pop();
                curr-=1;
            }
        }
        curr+=1;
        if(curr>ans){
            ans=curr;
        }
        pq.push(times[i].second);
    }
    cout<<ans;
   
    return 0;
}