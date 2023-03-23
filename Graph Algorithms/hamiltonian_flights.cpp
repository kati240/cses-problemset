// #include<iostream>
// using namespace std;



// int bit(int mask , int i){
//     if((mask & 1<<i) !=0){
//         return 1;
//     }
//     else{
//         return 0;
//     } 
// }
// int count_bit(int mask){
//     int count=0;
//     for(int i=0;i<=20;i++){
//         if(mask & 1<<i){
//             count+=1;
//         }
//     }
//     return count;
// }
// // set dp value of 1 to x one for initial setup , where adj[1][x]=true for further set for 





// int main(){
//     int n,m;
//     cin>>n>>m;
//     int adj[n][n];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             adj[i][j]=0;
//         }
//     }
//     for(int i=0;i<m;i++){
//         int a,b;
//         cin>>a>>b;
//         a-=1;
//         b-=1;
//         adj[a][b]=1;
//     }
//     int total_masks= 1<<(n+1)  -1 ;
//     long long int dp[total_masks+1][n];
//     for(int i=0;i<=total_masks;i++){
//         for(int j=0;j<n;j++){
//             dp[i][j]=0;
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(adj[0][i]==1){
//             int a=1<<i  +1; 
//             dp[a][i]=1; // visited 1 and ith place and ending place is i  and number of ways is 1 
//         }
//     }
//     for(int i=0;i<=total_masks;i++){
//         for(int j=0;j<n;j++){
//             int a=0;
//             for(int k=0;k<n;k++){
//                 if( dp[i ^ 1<<j][k] ){
//                     dp[i][j]+=dp[i ^ 1<<j][k];
//                 }
//             }
            
//         }
//     }







//     return 0;
// }

#include<iostream>
#define int long long
using namespace std;



const int MAXN = 20;
const int MOD = 1000000007;
int n, m;
int a, b;
int G[MAXN][MAXN];
int dp[1<<MAXN][MAXN];
int ans;

inline int lb(int a) {
  return a &- a;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a-1][b-1]++;
  }
  dp[1][0] = 1;
  for (int i = 1; i < (1<<n); i++) {
    for (int j = 0; j < n; j++) {
      if (!(i & (1<<j))) continue;
      dp[i][j] %= MOD;
      for (int k = 0; k < n; k++) {
        if (i & (1<<k)) continue;
        dp[i|(1<<k)][k] += dp[i][j] * G[j][k];
      }
    }
  }
  ans = dp[(1<<n)-1][n-1];
  cout << ans << "\n";
}