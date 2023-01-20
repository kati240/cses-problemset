#include<iostream>
using namespace std;

#include<vector>
int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  vector<vector<int>> dp(n, vector<int>(n, 0));  // passing 2-d arrays in c++ functions uuuf, learn other ways round it 
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      if (row[j] == '.') {
	if (i > 0) {
	  (dp[i][j] += dp[i-1][j]) %= mod;
	}
	if (j > 0) {
	  (dp[i][j] += dp[i][j-1]) %= mod;
	}
      } else {
	dp[i][j] = 0;
      }
    }
  }
  cout << dp[n-1][n-1] << endl;
}