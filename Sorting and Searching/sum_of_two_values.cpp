#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,target;
    scanf("%d %d",&n,&target);
    vector<pair<int,int> >values;
    int x;

    for(int i=0;i<n;i++){
        cin>>x;
        values.push_back(make_pair(x,i+1));
    }
    sort(values.begin(),values.end());
    int i=0;
    int j=n-1;
    while (i<j){  // two pointers 
        if(values[i].first+values[j].first==target){
            cout<<values[i].second<<" "<<values[j].second;
            return 0;
        }
        else if(values[i].first+values[j].first>target){
            j-=1;
        }
        else if(values[i].first+values[j].first<target){
            i+=1;
        }
    }
    cout<<"IMPOSSIBLE";
    
    return 0;
}