#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int weights[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    sort(weights,weights+n);
    int start=0;
    int end=n-1;
    int ans=0;
    int count=0;
    while(count!=n){  //similar methodology of implementation like apartments problem
        if(start==end){
            ans+=1;
            break;
        }
        if(weights[end]+weights[start]<=x){
            end-=1;
            start+=1;
            ans+=1;
            count+=2;
        }
        else{
            end-=1;
            count+=1;
            ans+=1;
        }

    }
    printf("%d",ans);
 
}