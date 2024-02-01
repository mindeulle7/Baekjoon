#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;


int n, m;

int arr[100][100];
int cheese[100][100];
bool visit[100][100];
int cnt = 1;

int Move[4][2] = {
	{0,1},{1,0},{0,-1},{-1,0}
};

bool inRange(int row, int col) {
	if (0 <= row && row < n && 0 <= col && col < m) {
		return true;
	}
	return false;
}


void bfs() {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ 0,0});
	visit[0][0] = true;
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextRow = current.first + Move[i][0];
			int nextCol = current.second + Move[i][1];
			if (inRange(nextRow, nextCol) && !visit[nextRow][nextCol]) {
				if (arr[nextRow][nextCol] == 0) {
					visit[nextRow][nextCol] = true;
					q.push({ nextRow,nextCol });
				}
				else {
					cheese[nextRow][nextCol]++;
				}
			}
		}
	}
}

int main() {
	int erasedCheese = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				erasedCheese++;
			}
		}
	}
	while (0 < erasedCheese) {
		bfs();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (2<= cheese[i][j]) {
					erasedCheese--;
					arr[i][j] = 0;
				}
			}
		}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		cnt++;
		memset(cheese, 0, sizeof(cheese));
	}
	cout << cnt -1 ;
}