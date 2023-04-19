#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char graph[26][26];
int visit[26][26] = { 0 };
int move_x[4] = { 1, -1, 0 ,0 };
int move_y[4] = { 0, 0, 1, -1 };

void input(int n);
void solve(int n);
int bfs(int start1, int start2);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	input(n);
	solve(n);
}

void input(int n) {
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			graph[i][j] = s[j-1];
		}
	}
}

void solve(int n) {
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == '1' && !visit[i][j]) {
				v.push_back(bfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0;i<v.size(); i++) {
		cout << v[i] << "\n";
	}
}

int bfs(int start1, int start2) {
	int cnt = 1;
	queue<pair<int, int>> q;
	visit[start1][start2]++;
	q.push(make_pair(start1, start2));
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = row + move_y[i];
			int next_col = col + move_x[i];
			if (next_row > 0 && next_col > 0) {
				if (graph[next_row][next_col] == '1' && !visit[next_row][next_col]) {
					q.push(make_pair(next_row, next_col));
					visit[next_row][next_col]++;
					cnt++;
				}
			}
		}
	}
	return cnt;
}