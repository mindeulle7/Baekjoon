#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int graph[1001][1001] = { 0 };

queue<int> q;
stack<int> s;

void bfs(int n, int v);
void dfs(int n, int v);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1][n2] = 1;
		graph[n2][n1] = 1;
	}
	dfs(n, v);
	bfs(n, v);
	
	
}

void bfs(int n, int v) {
	int check[1001] = { 0 };
	q.push(v);
	check[v]++;
	cout << v << " ";
	while (!q.empty()) {
		int index = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[index][i] && !check[i]) {
				cout << i << " ";
				q.push(i);
				check[i]++;
			}
		}
	}
}


void dfs(int n, int v) {
	int check[1001] = { 0 };
	s.push(v);
	check[v]++;
	cout << v << " ";
	while (!s.empty()) {
		int index = s.top();
		s.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[index][i] && !check[i]) {
				cout << i << " ";
				s.push(index);
				s.push(i);
				check[i]++;
				break;
			}
		}
	}
	cout << "\n";
}