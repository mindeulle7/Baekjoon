#include <iostream>
#include <queue>
using namespace std;

int graph[100001] = { 0 };
bool visit[100001] = { false };

int bfs(int n, int k);
void three_case(queue<int> q, int current);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
}

int bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	visit[n] = true;
	while (!q.empty()) {
		int current = q.front();
		if (current == k) {
			break;
		}
		q.pop();
		int next = current + 1;
		if (0 <= next && next <= 100000) {
			if (!visit[next]) {
				graph[next] = graph[current] + 1;
				q.push(next);
				visit[next] = true;
			}
			else if (graph[current] + 1 < graph[next]) {
				graph[next] = graph[current] + 1;
			}
		}
		next = current - 1;
		if (0 <= next && next <= 100000) {
			if (!visit[next]) {
				graph[next] = graph[current] + 1;
				q.push(next);
				visit[next] = true;
			}
			else if (graph[current] + 1 < graph[next]) {
				graph[next] = graph[current] + 1;
			}
		}
		next = current * 2;
		if (0 <= next && next <= 100000) {
			if (!visit[next]) {
				graph[next] = graph[current] + 1;
				q.push(next);
				visit[next] = true;
			}
			else if (graph[current] + 1 < graph[next]) {
				graph[next] = graph[current] + 1;
			}
		}
	}
	return graph[k];
}
