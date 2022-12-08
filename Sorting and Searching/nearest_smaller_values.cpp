#include<iostream>
#include<set>
#include<map>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
	stack<pair<int, int>> stack;
	stack.push({0, 0});

	for(int i = 1; i <= n; ++i) { // this is o(n) not n^2
		int a; cin >> a;
		while(!stack.empty() && stack.top().first >= a) stack.pop();
		cout << stack.top().second << " ";
		stack.push({a, i});
	}
    return 0;
}