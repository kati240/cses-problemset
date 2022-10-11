#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int applicantions[n];
    for(int i=0;i<n;i++){
        cin>>applicantions[i];
    }
    int available[m];
    for(int i=0;i<m;i++){
        cin>>available[i];
    }
    sort(applicantions,applicantions+n);
    sort(available,available+m);
    int ans=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(abs(applicantions[i]-available[j])<=k){
            ++i;
            ++j;
            ++ans;
        }
        else{
            if(applicantions[i]+k<available[j]){
                ++i;
            }
            if(available[j]+k<applicantions[i]){
                ++j;
            }

        }
    }
    
    cout<<ans;

}