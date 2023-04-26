#include <iostream>
#include <queue>
using namespace std;

char graph[101][101];
bool visit[101][101] = { 0 };
int MOVE[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void input(int N);
int g_solve(int N);
int p_solve(int N);
bool check(int N);
pair<int, int> find(int N);
void reset(int N);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	input(N);
	cout << g_solve(N) << " " << p_solve(N);
}

void input(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}
}

int g_solve(int N) {
	int cnt = 0;
	while (!check(N)) {
		queue<pair<int, int>> q;
		pair<int, int> p = find(N);
		char color = graph[p.first][p.second];
		visit[p.first][p.second] = true;
		q.push(make_pair(p.first, p.second));
		while (!q.empty()) {
			int current_x = q.front().first, current_y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = current_x + MOVE[i][0], next_y = current_y + MOVE[i][1];
				if (1 <= next_x && next_x <= N && 1 <= next_y && next_y <= N) {
					if (!visit[next_x][next_y] && graph[next_x][next_y] == color) {
						q.push(make_pair(next_x, next_y));
						visit[next_x][next_y] = true;
					}
				}
			}
		}
		cnt++;
	}
	reset(N);
	return cnt;
}

int p_solve(int N) {
	int cnt = 0;
	while (!check(N)) {
		queue<pair<int, int>> q;
		pair<int, int> p = find(N);
		char color = graph[p.first][p.second];
		visit[p.first][p.second] = true;
		q.push(make_pair(p.first, p.second));
		while (!q.empty()) {
			int current_x = q.front().first, current_y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = current_x + MOVE[i][0], next_y = current_y + MOVE[i][1];
				if (1 <= next_x && next_x <= N && 1 <= next_y && next_y <= N) {
					if (color == 'G' || color == 'R') {
						if (!visit[next_x][next_y] && (graph[next_x][next_y] == 'G' || graph[next_x][next_y] == 'R')) {
							q.push(make_pair(next_x, next_y));
							visit[next_x][next_y] = true;
						}
					}
					else {
						if (!visit[next_x][next_y] && graph[next_x][next_y] == color) {
							q.push(make_pair(next_x, next_y));
							visit[next_x][next_y] = true;
						}
					}
				}
			}
		}
		cnt++;
	}
	return cnt;
}

bool check(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				return false;
			}
		}
	}
	return true;
}

pair<int, int> find(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				return make_pair(i, j);
			}
		}
	}
}

void reset(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
		}
	}
}