#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct NODE {
	int node1;
	int node2;
	int cost;
	bool operator <(const NODE& n) const {
		return cost > n.cost;
	}
};

int n, m;
int sum;
int parent[200000];
priority_queue<NODE> pq;

int find(int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}

void merge(int node1, int node2, int cost) {
	node1 = find(node1);
	node2 = find(node2);
	if (node1 == node2) {
		return;
	}
	else if (node1 < node2) {
		parent[node2] = node1;
		sum += cost;
	}
	else {
		parent[node1] = node2;
		sum += cost;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		int res = 0;
		sum = 0;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < m; i++) {
			int node1, node2, cost;
			cin >> node1 >> node2 >> cost;
			pq.push({ node1,node2,cost });
			res += cost;
		}
		while (!pq.empty()) {
			NODE current = pq.top();
			pq.pop();
			merge(current.node1, current.node2, current.cost);
		}
		cout << res - sum << "\n";
	}
}