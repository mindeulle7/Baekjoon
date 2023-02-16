#include <iostream>
#include <algorithm>
using namespace std;

char arr[80][80];

int black(int n, int m) {
	char bl[8][8];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		char initial;
		if (i % 2 == 0) {
			initial = 'B';
		}
		else {
			initial = 'W';
		}
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				bl[i][j] = initial;
			}
			else {
				if (bl[i][j-1] == 'W') {
					bl[i][j] = 'B';
				}
				else {
					bl[i][j] = 'W';
				}
			}
		}
	}
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (bl[i - n][j - m] != arr[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int white(int n, int m) {
	char wh[8][8];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		char initial;
		if (i % 2 == 0) {
			initial = 'W';
		}
		else {
			initial = 'B';
		}
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				wh[i][j] = initial;
			}
			else {
				if (wh[i][j - 1] == 'W') {
					wh[i][j] = 'B';
				}
				else {
					wh[i][j] = 'W';
				}
			}
		}
	}
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (wh[i - n][j - m] != arr[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int minimum = 65;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			if (min(black(i, j), white(i, j)) < minimum) {
				minimum = min(black(i, j), white(i, j));
			}
		}
	}
	cout << minimum;
}