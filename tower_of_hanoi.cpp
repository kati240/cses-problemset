#include <iostream>
#include<vector>
using namespace std;
void fn_hanoi(vector<pair<int,int> > &s,long long int &ans,int n,int a,int b,int c){
    if(n>0){
        fn_hanoi(s,ans,n-1,a,c,b);  // recursion , transfer n-1 from a to b , then last ring from a to c then repeat
        ans+=1;
        //cout<<a<<" "<<c<<endl;
        s.push_back(make_pair(a,c));
        fn_hanoi(s,ans,n-1,b,a,c);
    }
    else{
        return;
    }
    }
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > s;

    long long int ans=0;
    
    fn_hanoi(s,ans,n,1,2,3);
    cout<<ans<<endl;
    for(int i=0;i<s.size();i++){
          cout << s[i].first << " "
             << s[i].second << endl;

    }

   

 return 0;


}