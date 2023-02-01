#include<iostream>
using namespace std;

int main(){
    int n, limit;
    cin>>n>>limit;
    int weights[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    pair<int,int> best[1<<n];// for subset i , contains elements rides(i), last(i)
    best[0]=make_pair(1,0);
    for(int i=1;i<(1<<n);i++){
        best[i]=make_pair(n+1,0);
        for(int j=0;j<n;j++){
            if(i & (1<<j) ){ // if jth element is in the set i 
                auto option =best[i^(1<<j)];// adding the j th person to a prev subset , by unsetting the bit with XOR
                if(option.second+weights[j]<=limit){
                    option.second+=weights[j];
                }
                else{
                    option.first+=1;
                    option.second=weights[j];
                }
                best[i]=min(best[i],option);
            }
        }
    }
    cout<<best[(1<<n) -1].first;
    return 0;
}