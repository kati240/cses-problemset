#include<iostream>
#include<functional>
using namespace std;


int rows, columns;
int vis[1010][1010];
char grid[1010][1010];


void dfs(int i,int j,int count){
        vis[i][j]=count;
        int dx[4]={0,-1,1,0};
        int dy[4]={-1,0,0,1};
        for(int k=0;k<4;k++){
            if(i+dx[k]<rows && i+dx[k]>=0 && j+dy[k]>=0 && j+dy[k]<columns){
                if(vis[i+dx[k]][j+dy[k]]==0){ 
                    dfs(i+dx[k],j+dy[k],count);
                }
            }
        }
        return ;
};

int main(){

    cin>>rows>>columns;

    string s;
    getline(cin,s);
    for(int i=0;i<rows;i++){
        getline(cin,s);
        for(int j=0;j<columns;j++){
            if(s[j]=='#'){
                vis[i][j]=-1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }



    int count_rooms=0;



    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(vis[i][j]==0){
                count_rooms+=1;
                dfs(i,j,count_rooms);
            }
        }
    
    }
    cout<<count_rooms;


    return 0;
}