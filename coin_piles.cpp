#include <iostream>
#include <queue>
using namespace std;
int main(){
    int t;
    
    cin>>t;

    while(t--){
        long long int a;
        long long int b;
        cin >> a >> b;    // if sum is div by three and the max is <=2*of the min it is possible 
        if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a ){
	        cout << "YES"<<endl;
        }
        else{
            cout << "NO"<<endl;
        }
    }
    return 0;
}