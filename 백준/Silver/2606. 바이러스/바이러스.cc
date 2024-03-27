#include <iostream>
using namespace std;

int parent[101];

int find(int node) {
	if (node == parent[node]) {
		return node;
	}
	return parent[node] = find(parent[node]);
}

void merge(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);
	if (node1 < node2) {
		parent[node2] = node1;
	}
	else {
		parent[node1] = node2;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (find(parent[i]) == 1) {
			sum++;
		}
	}
	cout << sum - 1;
}