#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

char arr[100][100];
bool check[100][100];
int cnt[100][100];
queue<pair<int, int>> q;
int move_x[4] = { 1,0,-1,0 };
int move_y[4] = { 0,1,0,-1 };

void assign(int n, int m);
void calcu(int n, int m, int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	assign(n, m);
	calcu(n, m, 0, 0);
	cout << cnt[n - 1][m - 1] + 1;
}


void assign(int n, int m) {
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			check[i][j] = false;
			cnt[i][j] = 0;
		}
	}
}


void calcu(int n, int m, int x, int y) {
	q.push(make_pair(x, y));
	check[y][x] = true;
	int nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + move_x[i];
			ny = y + move_y[i];

			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (!check[ny][nx] && arr[ny][nx] == '1') {
					check[ny][nx] = true;
					cnt[ny][nx] = cnt[y][x] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
}