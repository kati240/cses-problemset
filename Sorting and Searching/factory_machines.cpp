#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    long long int n,t;
    vector<long long int>times;
    cin>>n>>t;
    long long int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        times.push_back(temp);
    }
    // binary search for the answer from max int to 1  
    long long int ans=0;
    long long int low=0;
    long long int high=1e18;
    while (low<=high)
    {
       long long int time=(low+high)/2;
       long long int a=0;
        for(int i=0;i<n;i++){
            a+=time/times[i];
            if(a>=t){
                break;
            }
        }
        if(a>=t){
            ans=time;
            high=time-1;
        }
        else{
            low=time+1;
        }
    }
    cout<<ans;
    return 0;
}
