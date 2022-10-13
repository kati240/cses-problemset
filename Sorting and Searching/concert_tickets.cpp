#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    int m;
    scanf("%d %d",&n,&m);
    multiset<int>tickets;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        tickets.insert(x);
    }
   int t;
    for(int i=0;i<m;i++){
        cin>>t;
        auto it=tickets.upper_bound(t);
        if (it==tickets.begin()){
			cout<< -1 << "\n";
		}
		else{
			cout<< *(--it) << "\n";
			tickets.erase(it);
		}
    }
}