#include<iostream>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int teleporter[n+1][30];
    for(int i=0;i<=n;i++){
        for(int j=0;j<30;j++){
            teleporter[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>teleporter[i][0];
    }
    for(int j=1;j<30;j++){
        for(int i=1;i<=n;i++){
            teleporter[i][j]=teleporter[teleporter[i][j-1]][j-1]; // storing in powers of 2 , like the idea of a fenwick tree
        }
    }
    int start,x;
    while (q--)
    {
       
        cin>>start>>x;
        for(int i=0;i<30;i++){
            if(x & (1<<i)){
                start=teleporter[start][i];
            }
        }
        cout<<start<<"\n";
    }
    return 0;
}
