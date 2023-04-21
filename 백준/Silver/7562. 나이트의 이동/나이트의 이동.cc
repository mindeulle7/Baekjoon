#include <iostream>
#include <queue>
using namespace std;

int move_night[8][2] = {
	{2,1}, {1,2}, {-2,1}, {-1,2},
	{2,-1}, {1,-2}, {-2,-1}, {-1,-2}
};

int solve(int n, int graph[][301], bool visit[][301], int start_x, int start_y, int end_x, int end_y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int graph[301][301] = { 0 };
		bool visit[301][301] = { 0 };
		int n;
		cin >> n;
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y >> end_x >> end_y;
		cout << solve(n, graph, visit, start_x, start_y, end_x, end_y) << "\n";	
	}
}

int solve(int n, int graph[][301], bool visit[][301], int start_x, int start_y, int end_x, int end_y) {
	queue<pair<int,int>> q;
	q.push(make_pair(start_x, start_y));
	visit[start_x][start_y] = true;
	while (q.front().first != end_x || q.front().second != end_y) {
		pair<int, int> current = make_pair(q.front().first, q.front().second);
		q.pop();
		for (int i = 0; i < 8; i++) {
			int next_x = current.first + move_night[i][0];
			int next_y = current.second + move_night[i][1];
			if (0 <= next_x && next_x < n) {
				if (0 <= next_y && next_y < n) {
					if (!visit[next_x][next_y]) {
						graph[next_x][next_y] = graph[current.first][current.second] + 1;
						q.push(make_pair(next_x, next_y));
						visit[next_x][next_y] = true;
					}
					else if (graph[current.first][current.second] < graph[next_x][next_y] - 1) {
						graph[next_x][next_y] = graph[current.first][current.second] + 1;
						q.push(make_pair(next_x, next_y));
					}
				}
			}
		}
	}
	return graph[end_x][end_y];
}