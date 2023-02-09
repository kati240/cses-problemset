#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int rows, columns, start_x,start_y,end_x,end_y;
string ans;
queue <pair<int , int > >q;

int vis[1010][1010];
char direction[1010][1010];

int bfs(queue <pair<int , int > >q){
    int flag=0;
    while(q.size() ){
            pair<int , int >  a;
            a=q.front();
            q.pop();
            int i=a.first;
            int j=a.second;
            vis[i][j]= 1;
            int dx[4]={0,-1,1,0};
            int dy[4]={-1,0,0,1};
            string dir="LUDR";
            for(int k=0;k<4;k++){
                if(i+dx[k]<rows && i+dx[k]>=0 && j+dy[k]>=0 && j+dy[k]<columns){
                    if(vis[i+dx[k]][j+dy[k]]==0 && direction[i+dx[k]][j+dy[k]]=='Q'){ 
                        q.push(make_pair(i+dx[k],j+dy[k]));
                        direction[i+dx[k]][j+dy[k]]=dir[k];
                    }
                    if(i+dx[k]==end_x && j+dy[k]==end_y){
                        queue <pair<int , int > >empty;
                        swap( q, empty );
                        flag=1;
                        break;
                        return 1 ;
                    }
                }
            }
            if(flag){
                break;
                return 1 ;
            }
    }  
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>rows>>columns;
    string s;
    getline(cin,s);
    for(int i=0;i<rows;i++){
        getline(cin,s);
        for(int j=0;j<columns;j++){
            if(s[j]=='#'){
                vis[i][j]=-1;
            }
            else if(s[j]=='.'){
                vis[i][j]=0;
            }
            else if(s[j]=='A'){
                vis[i][j]=0;
                start_x=i;
                start_y=j;
            }
            else if(s[j]=='B'){
                vis[i][j]=0;
                end_x=i;
                end_y=j;
            }
        }
    }
    q.push(make_pair(start_x,start_y));
    for(int o=0;o<1010;o++){
    for(int p=0;p<1010;p++){
        direction[o][p]='Q';
        }
    }
    int d=bfs(q);
    if(direction[end_x][end_y]!='Q'){
        cout<<"YES"<<endl;
        int curr_x=end_x;
        int curr_y=end_y;
        while(!(curr_x==start_x && curr_y==start_y)){
            ans.push_back(direction[curr_x][curr_y]);
            switch (direction[curr_x][curr_y])
            {
            case 'U':
                curr_x+=1;
                break;
            case 'D':
                curr_x-=1;
                break;
            case 'L':
                curr_y+=1;
                break;
            case 'R':
                curr_y-=1;
                break;
            default:
                break;
            }   
        }
        cout<<ans.length()<<endl;
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;   
    }
    else{
        cout<<"NO";
    }
    return 0;
}