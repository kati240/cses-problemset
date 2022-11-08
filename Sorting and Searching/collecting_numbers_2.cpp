#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    int positions[n+2];
    positions[0]=0;
    positions[n+1]=n+1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        positions[arr[i]]=i+1;
    }
    int seen[n+1];
    for(int as=0;as<=n;as++){
        seen[as]=0;
    }
    

    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            ans+=1;
            seen[1]=1;
        }
        else{
            if(seen[arr[i]-1]==0){
                ans+=1;
            }
            seen[arr[i]]=1;

        }
        
    }
    int temp;
    for(int j=0;j<m;j++){
        set<pair<int,int> >s;
        int a,b;
        cin>>a>>b;

        if(positions[arr[a-1]]<positions[arr[a-1]-1]){      // dont try to overcomplicate just undo and redo 
            ans-=1;
        }
        if(positions[arr[a-1]+1]<positions[arr[a-1]]){
            ans-=1;
        }
        if(arr[b-1]-1 !=arr[a-1] && positions[arr[b-1]-1]>positions[arr[b-1]]){
            ans-=1;
        }
        if(arr[b-1]+1 !=arr[a-1] && positions[arr[b-1]+1]<positions[arr[b-1]]){
            ans-=1;
        }
        positions[arr[a-1]]=b;
        positions[arr[b-1]]=a;

        temp=arr[a-1];
        arr[a-1]=arr[b-1];
        arr[b-1]=temp;
        if(positions[arr[a-1]]<positions[arr[a-1]-1]){
            ans+=1;
        }
        if(positions[arr[a-1]+1]<positions[arr[a-1]]){
            ans+=1;
        }
        if(arr[b-1]-1 !=arr[a-1] && positions[arr[b-1]-1]>positions[arr[b-1]]){
            ans+=1;
        }
        if(arr[b-1]+1 !=arr[a-1] && positions[arr[b-1]+1]<positions[arr[b-1]]){
            ans+=1;
        }


        


        cout<<ans<<endl;
        
    }
   
    


    return 0;
}