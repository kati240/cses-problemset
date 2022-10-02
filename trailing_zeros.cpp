#include <iostream>


using namespace std;

int main(){
    int n;
    cin>>n;

    int ans=0;
   int curr=5;
    while(n>=curr){  // classic maths problem of JEE 
        ans+=int(n/curr);
        curr*=5;
    }


cout<<ans;

    return 0;
}