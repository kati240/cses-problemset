#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+3;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> lead;
int n, m, conn_comp = 0;
 
void dfs(int x) {// plain good ol' DFS
	visited[x] = true;
	for(auto i : adj[x]) {
		if(!visited[i]) {
			dfs(i);
		}
	}
}
 
int main() {
	cin >> n >> m;
 
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
 
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			conn_comp++;
			lead.push_back(i);
			dfs(i);
		}
	}
	cout << '\n';
	cout << conn_comp-1 << '\n';
	int a, b;
	a = lead[0];
	for(int i = 1; i < (int)lead.size(); i++) {
		b = lead[i];
		cout << a << " " << b << '\n';
		a = b;
	}
    cout << '\n';
    return 0;
}