// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// char grid[1001][1001];
// int n,m;
// int start_x,start_y;
// vector<pair<int ,int > >monsters;
// vector<pair<int ,int > >gates;
// int answer_x,answer_y;
// char direction[1010][1010];

// bool bfs(int x,int y){ // if we ever reach m before a after bfs from escape gate we return 0 else 1 
//     int vis[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             vis[i][j]=0;
//         }
//     }
//     queue<pair<int,int > >q;
//     q.push(make_pair(x,y));
//     int flag=0;
//     int found_m=0;
//     int found_a=0;
//     while(q.size() ){
//         int x=q.size();
//         for(int lmao=0;lmao<x;lmao++){
//             pair<int , int >  a;
//             a=q.front();
//             q.pop();
//             int i=a.first;
//             int j=a.second;
//             if(grid[i][j]=='M'){
//                 found_m=1;
//             }
//             if(grid[i][j]=='A'){
//                 found_a=1;
//             }
//             vis[i][j]= 1;
//             int dx[4]={0,-1,1,0};
//             int dy[4]={-1,0,0,1};
//             string dir="LUDR";
//             for(int k=0;k<4;k++){
//                 if(i+dx[k]<n && i+dx[k]>=0 && j+dy[k]>=0 && j+dy[k]<m){
//                     if(vis[i+dx[k]][j+dy[k]]==0 && grid[i+dx[k]][j+dy[k]]!='#'){ 
//                         q.push(make_pair(i+dx[k],j+dy[k]));
//                         direction[i+dx[k]][j+dy[k]]=dir[k];
//                     }
//                 }
//             }
//         }
//         if(found_a==1 && found_m==0){
//             return 1;
//         }
//         else if(found_m){
//             return 0;
//         }
//     }
//     if(found_a && !found_m){
//         return 1;
//     }
//     return 0;
// }
// int main(){
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//             if(grid[i][j]=='M'){
//                 monsters.push_back(make_pair(i,j));
//             }
//             if(grid[i][j]=='A'){
//                 start_x=i;
//                 start_y=j;
//             }
//             if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]=='.'){
//                 gates.push_back(make_pair(i,j));
//             }
//         }
//     }
//     int flag=0;
//     for(int i=0;i<gates.size();i++){
//         if(bfs(gates[i].first,gates[i].second)){
//             answer_x=gates[i].first;
//             answer_y=gates[i].second;
//             flag=1;
//             break;
//         }
//     }
//     if(flag){
//         cout<<"YES"<<endl;
//         string ans;
//         int curr_x=start_x;
//         int curr_y=start_y;
//         while(!(curr_x==answer_x && curr_y==answer_y)){
//             ans.push_back(direction[curr_x][curr_y]);
//             switch (direction[curr_x][curr_y])
//             {
//             case 'U':
//                 curr_x+=1;
//                 break;
//             case 'D':
//                 curr_x-=1;
//                 break;
//             case 'L':
//                 curr_y+=1;
//                 break;
//             case 'R':
//                 curr_y-=1;
//                 break;
//             default:
//                 break;
//             }   
//         }
//         cout<<ans.size()<<endl;
//         for(int i=0;i<ans.size();i++){
//             if(ans[i]=='L'){
//                 cout<<'R';
//             }
//             if(ans[i]=='R'){
//                 cout<<'L';
//             }
//             if(ans[i]=='U'){
//                 cout<<'D';
//             }
//             if(ans[i]=='D'){
//                 cout<<'U';
//             }
//         }
//     }
//     else{
//         if(start_x==0 || start_x==n-1 || start_y==0 || start_y==m-1){
//             cout<<"YES"<<endl;
//             cout<<0<<endl;
//         }
//         else{
//             cout<<"NO";
//         }
//     }
//     return 0;
// } //  my Time limit exceeded solution 



#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#define pii pair<int, int>
#define mn 1005
using namespace std;

int N, M;
queue<pii> q;
int paths[mn][mn];
pii from[mn][mn];
int oo = INT_MAX;
pii A;
string ans;
bool possible = false;

void retrace(pii node){  // retrace from final node, adding direction from previous node to a string. This string will be backwards but will be reversed before output.
	pii origin = from[node.first][node.second];
	if(origin ==  pii(0,0)) return;
	if(origin.first == node.first+1) ans.push_back('U');
	if(origin.first == node.first-1) ans.push_back('D');
	if(origin.second == node.second+1) ans.push_back('L');
	if(origin.second==node.second-1) ans.push_back('R');
	retrace(origin);

}
void check(pii origin, pii dest){ // check if the considered destination may be traveled to, clever way to assign for monsters and check when bfsing from A 
	int pl = paths[origin.first][origin.second];
	if(pl+1<paths[dest.first][dest.second]){
		paths[dest.first][dest.second]  = pl+1;
		q.push(dest);
		from[dest.first][dest.second] = origin;
	}
}
bool mora = false; // false if bfs for monsters, true if bfs for A
void bfs(){
	while(!q.empty()){
		pii loc = q.front(), next; q.pop();
		next = loc; next.first++; check(loc, next); // go through adjacent locations
		next = loc; next.first--; check(loc, next);
		next = loc; next.second++; check(loc, next);
		next = loc; next.second--; check(loc, next);
		if(mora && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)){
			cout << "YES" << endl;
			cout << paths[loc.first][loc.second] << endl;
			retrace(loc);
			possible = true;
			return;
		}
	}
}
int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		string s;
		cin >> s;
		for(int j = 1; j <= M; j++){
			paths[i][j] = oo;
			if(s[j-1] == '#') paths[i][j] = 0;
			if(s[j-1] == 'M') {q.push(pii(i,j)); paths[i][j]  = 0;}
			if(s[j-1] == 'A') {A.first = i; A.second = j;}
		}
	}
	bfs(); // monster bfs
	mora = true; // change next bfs to A bfs
	from[A.first][A.second] = pii(0,0); // give the retrace a terminating location
	paths[A.first][A.second] = 0; q.push(A); // get ready for next bfs
	bfs(); // bfs with A
	if(possible){
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	else cout << "NO" << endl;
}