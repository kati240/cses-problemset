#include <iostream>
#include<algorithm>
using namespace std;


int arr_left[15]={0};
int arr_right[15]={0};
int col[8]={0};
int ans=0;
int board[8][8]={0};
void solve(int row){// iterate through a defined variable and use global arrays to avoid argument passing 
    if(row==8){
        ans+=1;
    }
    else{
        for(int i=0;i<8;i++){
            if(col[i]|| arr_left[row+i]|| arr_right[7-row+i]){
                continue;
            }
            else{
                if(board[row][i]==0){
                    col[i]=1;
                    arr_left[row+i]=1;
                    arr_right[7-row+i]=1;
                    solve(row+1);
                    col[i]=0;
                    arr_left[row+i]=0;
                    arr_right[7-row+i]=0;
                }
            }
        }
    }
}


int main(){
    for(int i=0;i<8;i++){
        string s;
        getline(cin,s);
        int curr=0;
        for(auto x:s){
            if(x=='*'){
                board[i][curr]=-1;
            }
            curr+=1;
        }
    }
    solve(0);
    cout<<ans;
}