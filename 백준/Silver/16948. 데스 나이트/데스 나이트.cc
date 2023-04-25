#include <iostream>
#include <queue>
using namespace std;

int graph[201][201] = { 0 };
bool visit[201][201] = { 0 };
int move_knight[6][2] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };

int solve(int n, int start1, int start2, int end1, int end2);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, start1, start2, end1, end2;
	cin >> n >> start1 >> start2 >> end1 >> end2;
	cout << solve(n, start1, start2, end1, end2);
}

int solve(int n, int start1, int start2, int end1, int end2) {
	queue<pair<int, int>> q;
	visit[start1][start2] = true;
	q.push(make_pair(start1, start2));
	while (!q.empty()) {
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int next_x = current_x + move_knight[i][0];
			int next_y = current_y + move_knight[i][1];
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
				if (!visit[next_x][next_y]) {
					graph[next_x][next_y] = graph[current_x][current_y] + 1;
					visit[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
				else if (graph[current_x][current_y] + 1 < graph[next_x][next_y]) {
					graph[next_x][next_y] = graph[current_x][current_y] + 1;
				}
			}
		}
	}
	if (!graph[end1][end2]) {
		return -1;
	}
	else {
		return graph[end1][end2];
	}
}