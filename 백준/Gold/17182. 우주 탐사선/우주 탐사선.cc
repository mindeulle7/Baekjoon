#include <iostream>
using namespace std;

int n, start;
int adj[10][10];
int visit[10];
int minimum = 2<<28;


void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

void recursion(int current, int cnt) {
	if (minimum < visit[current]) {
		return;
	}
	if (cnt == n) {
		minimum = min(minimum, visit[current]);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == -1) {
			visit[i] = visit[current] + adj[current][i];
			recursion(i, cnt + 1);
			visit[i] = -1;
		}
	}
}


int main() {
	cin >> n >> start;
	for (int i = 0; i < n; i++) {
		visit[i] = -1;
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	floyd();
	visit[start] = 0;
	recursion(start, 1);
	cout << minimum;
}