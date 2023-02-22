#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> radj[n+1];
    int indegree[n+1];
    for(int i=0;i<=n;i++){
        indegree[i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
        indegree[b]++;
    }
    int dist[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=0;
    }
    vector<int>topological;
    queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int loc = q.front();
		q.pop();
		topological.push_back(loc);
		for (auto i : adj[loc])
			if (--indegree[i] == 0)
				q.push(i);
	}
    dist[1]=1;
    for(int i=1;i<n;i++){
        for(auto previous: radj[topological[i]]){// dp[next]=dp[next]+dp[prev]
            dist[topological[i]]+=dist[previous];
            dist[topological[i]]%=int(1e9+7);
        }

    }
    cout<<dist[n]<<endl;
    return 0;
}