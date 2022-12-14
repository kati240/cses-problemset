#include<iostream>
#include<map>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int a[n];
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        arr[i]=t;
    }
    map<int,int>m;
    int left=0;
    int right=0;
    long long int ans=0;
    long long int curr=1;
    while(left<=right ){
        if(right<n-1){
            if(m.size()<=k){
                if(m.size()<k){
                    if( m.find(arr[right])==m.end()){
                        m.insert(make_pair(arr[right],1));
                    }
                    else{
                        m[arr[right]]+=1;
                    }
                right+=1;
                curr+=1;
                }
                else{
                     if( m.find(arr[right])!=m.end()){
                        m[arr[right]]+=1; 
                        right+=1;
                        curr+=1;
                    }
                    else{
                        curr-=1;
                        ans+=curr;
                        m[arr[left]]-=1;
                        if(m[arr[left]]==0){
                            m.erase(arr[left]);
                        }
                        left+=1;
                    }
                }    
            }
        }
        else if(right==n-1){ 
            if( m.find(arr[right])==m.end()){
                m.insert(make_pair(arr[right],1));
            }
            else{
                m[arr[right]]+=1;
            }
            if(m.size()>k){
                m[arr[left]]-=1;
                if(m[arr[left]]==0){
                     m.erase(arr[left]);
                }
                ans+=(curr-1);
                curr-=1;
            }
            else{
                ans+=curr;
                curr-=1;  
            }
            left+=1;
        }
    }
    cout<<ans;
    return 0;
}