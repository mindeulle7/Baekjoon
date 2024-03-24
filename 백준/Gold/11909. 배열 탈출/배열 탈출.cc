#include <iostream>
#include <queue>
using namespace std;
#define INF (1<<31)-1


struct NODE {
	int row;
	int col;
	int value;
	int cost;
	bool operator<(const NODE& n) const {
		return cost > n.cost;
	}
};

int n;
int arr[2300][2300];
int dist[2300][2300];

int mv[2][2] = {
	{0,1},{1,0}
};

bool isRange(int row, int col) {
	if (0 <= row && row < n && 0 <= col && col < n) {
		return true;
	}
	return false;
}

void Dijkstra() {
	priority_queue<NODE> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}
	pq.push({ 0,0,arr[0][0],0 });
	dist[0][0] = 0;
	while (!pq.empty()) {
		NODE current = pq.top();
		/*cout << "current = " << current.row << " " << current.col << endl;*/
		if (current.row == n - 1 && current.col == n - 1) {
			cout << dist[current.row][current.col];
			return;
		}
		pq.pop();
		for (int i = 0; i < 2; i++) {
			int nextRow = current.row + mv[i][0];
			int nextCol = current.col + mv[i][1];
			if (isRange(nextRow, nextCol)) {
				if (current.value <= arr[nextRow][nextCol] && current.cost + (arr[nextRow][nextCol] - current.value) + 1 < dist[nextRow][nextCol]) {
					pq.push({ nextRow,nextCol,arr[nextRow][nextCol],current.cost + (arr[nextRow][nextCol] - current.value) + 1 });
					dist[nextRow][nextCol] = current.cost + (arr[nextRow][nextCol] - current.value) + 1;
				}
				if(arr[nextRow][nextCol] < current.value && current.cost < dist[nextRow][nextCol]){
					pq.push({ nextRow,nextCol,arr[nextRow][nextCol],current.cost });
					dist[nextRow][nextCol] = current.cost;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	Dijkstra();
	return 0;
}