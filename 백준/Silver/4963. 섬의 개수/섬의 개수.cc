#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int check[50][50];
queue<pair<int, int>> q;
int w, h;

int move_x[8] = { 1,1,1,-1,-1,-1,0,0 };
int move_y[8] = { 0,1,-1,0,1,-1,1,-1 };

void assign();
int solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		assign();
		if (w == 0 || h == 0) {
			break;
		}
		cout << solve() << "\n";
	}

}

void assign() {
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			check[i][j] = false;
		}
	}
}

int solve() {
	int cnt = 0;
	int x, y;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] && !check[i][j]) {
				q.push(make_pair(j, i));
				check[i][j] = true;
				cnt++;
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int k = 0; k < 8; k++) {
						int nx = x + move_x[k];
						int ny = y + move_y[k];
						if (0 <= nx && nx < w && 0 <= ny && ny < h && !check[ny][nx] && map[ny][nx]) {
							check[ny][nx] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	return cnt;
}