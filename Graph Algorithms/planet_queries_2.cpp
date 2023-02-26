// #include<iostream>
// #include<string.h>
// #include<stack>
// #include<set>
// #include<map>
// #include<vector>
// using namespace std;

// int main(){
//     int n,q;
//     cin>>n>>q;
//     int teleporters[n+1];
//     int tree[n+1]; 
//     int connecting_node[n+1];
//     int dist[n+1];
//     int type[n+1];
//     map<int,int > tree_parent_node_mapping;
//     memset(tree,0, n+1 * sizeof(int));
//     memset(dist,0, n+1 * sizeof(int));
//     memset(type,0, n+1 * sizeof(int));
//     memset(connecting_node,0, n+1 * sizeof(int));
//     teleporters[0]=0;
//     for(int i=0;i<n;i++){
//         int a,b;
//         cin>>a>>b;
//         teleporters[a]=b;
//     }
//     int connected_component=1;
//     for(int i=1;i<=n;i++){
//         if(tree[i]==0){
//             set<int> nodes;
//             int fill=0;
//             stack<int>s;
//             s.push(i);
//             while (s.size()){
//                 int curr=s.top();
//                 s.pop();
//                 if(tree[curr]==0){
//                     if(nodes.find(curr)!=nodes.end()){
//                         nodes.insert(curr);
//                         s.push(teleporters[curr]);
//                     }
//                     else{
//                         if(curr!=i){
//                             connecting_node[i]=curr;
//                         }
//                         break;
//                     } 
//                 }
//                 else{
//                     fill=tree[curr];
//                     connecting_node[i]=curr;
//                     break;
                    
//                 }
//             }
//             if(fill==0){
//                 fill=connected_component;
//                 connected_component+=1;
//             }
//             for(auto itr: nodes){
//                 tree[itr]=fill;
//             }
//             int distance=0;
//             int curr=i;
//             vector<int>temp;
//             while (curr!=connecting_node[i]){
//                 curr=teleporters[curr];
//                 distance+=1;
//                 temp.push_back(curr);
//                 type[curr]=2;
//                 connecting_node[curr]=connecting_node[i];
//             }
//             for(int j=0;j<temp.size();j++){
//                 dist[temp[j]]=distance;
//                 distance-=1;
//             }
//             if(dist[connecting_node[i]]==0){
//                 tree_parent_node_mapping[fill]=connecting_node[i];
//                 int curr=connecting_node[i];
//                 int len=0;
//                 type[curr]=1;
//                 while (curr!=connecting_node[i]){
//                     len+=1;
//                     type[curr]=1;
//                     dist[curr]=len;
//                     curr=teleporters[curr];
//                 }
//                 dist[curr]=len+1;
//             }
//         }
//     }
//     long long int teleporter[n+1][30];
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<30;j++){
//             teleporter[i][j]=0;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         teleporter[i][0]=teleporters[i];
//     }
//     for(int j=1;j<30;j++){
//         for(int i=1;i<=n;i++){
//             teleporter[i][j]=teleporter[teleporter[i][j-1]][j-1]; // storing in powers of 2 , like the idea of a fenwick tree
//         }
//     }

//     for(int i=0;i<q;i++){
//         int a,b;
//         cin>>a>>b;
//         if(tree[a]!=tree[b]){
//             cout<<-1<<endl;
//         }
//         else{
//             if(type[a]==type[b] && type[a]==2){
//                 if(connecting_node[a]==connecting_node[b]){
//                     if(dist[a]<dist[b]){
//                         cout<<-1<<endl;
//                     }
//                     else{
//                         int jump=dist[a]-dist[b];

//                         for(int k=0;k<30;k++){
//                         if(jump & (1<<k)){
//                             a=teleporter[a][k];
//                         }
//                         }
//                         if(a==b){
//                             cout<<jump<<endl;
//                         }
//                         else{
//                             cout<<-1<<endl;
//                         }
//                     }
//                 }
//                 else{
//                     cout<<-1<<endl;
//                 }
//             }
//             else if(type[a]==type[b] && type[a]==1){
//                 int node=tree_parent_node_mapping[tree[a]];
//                 if(dist[b]>dist[a]){
//                     cout<<dist[b]-dist[a]<<endl;
//                 }
//                 else{
//                     cout<< dist[node]-(dist[a]-dist[b])<<endl;
//                 }
//             }
//             else if(type[a]==1 && type[b]==2){
//                 cout<<-1<<endl;
//             }
//             else if(type[a]==2 && type[b]==1){
//                 int dist_a=dist[connecting_node[a]];
//                 int node=tree_parent_node_mapping[tree[a]];
//                 if(dist[b]>dist_a){
//                     cout<<dist[b]-dist_a + dist[a]<<endl;
//                 }
//                 else{
//                     cout<< dist[node]-(dist_a-dist[b]) + dist[a]<<endl;
//                 }
//             }
//         }
//     }
//     return 0;
// }



#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

int main() {
	int planet_num;
	int query_num;
	std::cin >> planet_num >> query_num;
	vector<int> next(planet_num);
	vector<vector<int>> before(planet_num);
	for (int p = 0; p < planet_num; p++) {
		std::cin >> next[p];
		next[p]--;
		before[next[p]].push_back(p);
	}

	/* 
	 * -2 = We haven't even got to processing this planet yet.
	 * -1 = This node is part of a tree.
	 * >= 0: the ID of the cycle the planet belongs to.
	 */
	vector<int> cycle_id(planet_num, -2);
	// Each map, given a planet #, returns the index of that planet in the cycle.
	vector<std::map<int, int>> cycles;
	for (int p = 0; p < planet_num; p++) {
		if (cycle_id[p] != -2) {
			continue;
		}
		vector<int> path{p};
		int at = p;
		while (cycle_id[next[at]] == -2) {
			at = next[at];
			cycle_id[at] = -3;  // Leave breadcrumbs for this iteration
			path.push_back(at);
		}
		
		std::map<int, int> cycle;
		bool in_cycle = false;
		for (int i : path) {
			in_cycle = in_cycle || i == next[at];
			if (in_cycle) {
				cycle[i] = cycle.size();
			}
			cycle_id[i] = in_cycle ? cycles.size() : -1;
		}
		cycles.push_back(cycle);
	}

	/*
	 * Precalculate the distance from each planet to its cycle with BFS.
	 * (cyc_dist[p] = 0) if p is part of a cycle.
	 */
	vector<int> cyc_dist(planet_num);
	for (int p = 0; p < planet_num; p++) {
		// Check if this planet is part of a cycle.
		if (cycle_id[next[p]] == -1 || cycle_id[p] != -1) {
			continue;
		}
		cyc_dist[p] = 1;
		vector<int> stack(before[p]);
		while (!stack.empty()) {
			int curr = stack.back();
			stack.pop_back();
			cyc_dist[curr] = cyc_dist[next[curr]] + 1;
			stack.insert(stack.end(), before[curr].begin(), before[curr].end());
		}
	}

	// Intialize the binary jumping arrays.
	int log2 = std::ceil(std::log2(planet_num));
	vector<vector<int>> pow2_ends(planet_num, vector<int>(log2 + 1));
	for (int p = 0; p < planet_num; p++) {
		pow2_ends[p][0] = next[p];
	}
	for (int i = 1; i <= log2; i++) {
		for (int p = 0; p < planet_num; p++) {
			pow2_ends[p][i] = pow2_ends[pow2_ends[p][i - 1]][i - 1];
		}
	}

	/*
	 * Given a starting planet & dist, returns the planet we end up at
	 * if we use the teleporter dist times.
	 */
	auto advance = [&] (int pos, int dist) {
		for (int pow = log2; pow >= 0; pow--) {
			if ((dist & (1 << pow)) != 0) {
				pos = pow2_ends[pos][pow];
			}
		}
		return pos;
	};
	for (int q = 0; q < query_num; q++) {
		int u, v;  // going from u to v
		std::cin >> u >> v;
		u--;
		v--;
		if (cycle_id[pow2_ends[u][log2]] != cycle_id[pow2_ends[v][log2]]) {
			cout << -1 << '\n';
			continue;
		}
		if (cycle_id[u] != -1 || cycle_id[v] != -1) {
			if (cycle_id[v] == -1 && cycle_id[u] != -1) {
				cout << -1 << '\n';
				continue;
			}
			// Handle the 2nd & 3rd cases at the same time.
			int dist = cyc_dist[u];
			int u_cyc = advance(u, cyc_dist[u]);  // The root of u's tree
			
			std::map<int, int>& cyc = cycles[cycle_id[u_cyc]];  // u and v's cycle
			int u_ind = cyc[u_cyc];
			int v_ind = cyc[v];
			int diff = u_ind <= v_ind ? v_ind - u_ind : cyc.size() - (u_ind - v_ind);
			cout << dist + diff << '\n';
		} else {
			if (cyc_dist[v] > cyc_dist[u]) {
				cout << -1 << '\n';
				continue;
			}
			int diff = cyc_dist[u] - cyc_dist[v];
			cout << (advance(u, diff) == v ? diff : -1) << '\n';
		}
	}
}