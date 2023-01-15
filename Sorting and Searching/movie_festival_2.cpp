#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


bool sortbysec(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> >movies;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        movies.push_back(make_pair(a,b));
    }
    sort(movies.begin(),movies.end(), sortbysec);
    int ans=0;
    multiset<int>end_times;
    for(int i=0;i<k;i++){
        end_times.insert(0);
    }
    for(int i=0;i<n;i++){
        auto it =end_times.upper_bound(movies[i].first);
        if(it==end_times.begin()){
            continue;
        }
        end_times.erase(--it);
        end_times.insert(movies[i].second);
        ans+=1;
    }
    cout<<ans;
    return 0;

}