#include <bits/stdc++.h>
using namespace std;

const long long int N = 100005;
const long long int INF = 1e18;

long long int n, m;
vector<pair<int, int>> adj[N]; // adjacency list to store the flight connections
long long int dist[N][2]; // minimum distance from the source to each vertex, using/without using the discount coupon
bool used[N][2]; // whether a vertex has been processed, using/without using the discount coupon

void dijkstra(long long int s) {
    priority_queue<pair<pair<long long int,long long  int>,long long  int>, vector<pair<pair<long long int,long long  int>,long long  int>>, greater<pair<pair< long long int,long long  int>,long long  int>>> pq;
    pq.push({{0, 0}, s});
    dist[s][0] = 0;
    dist[s][1] = 0;
    
    while (!pq.empty()) {
        long long int u = pq.top().second;
        long long int used_coupon = pq.top().first.second;
        pq.pop();
        
        if (used[u][used_coupon]) continue;
        used[u][used_coupon] = true;
        
        for (auto [v, w] : adj[u]) {
            long long int cost = w;
            if (dist[u][used_coupon] + cost < dist[v][used_coupon]) {
                dist[v][used_coupon] = dist[u][used_coupon] + cost;
                pq.push({{dist[v][used_coupon], used_coupon}, v});
            }
            if (used_coupon == 0 && dist[u][0] + cost / 2 < dist[v][1]) { // using the discount coupon
                dist[v][1] = dist[u][0] + cost / 2;
                pq.push({{dist[v][1], 1}, v});
            }
        }
    }
}

 int main() {
    cin >> n >> m;
    for (long long int i = 1; i <= m; i++) {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    
    fill(&dist[0][0], &dist[0][0] + N*2, INF);
    dijkstra(1);
    
    cout << dist[n][1] << endl;// dont meme with chatgpt 
    
    return 0;
}
