#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[2001];
int dp[2001][2001] = { 0 };

void assign(int N);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, S, E;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	assign(N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << dp[E][S] << "\n";
	}
}

void assign(int N) {
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] != arr[i]) {
				dp[i][j] = 0;
			}
			else {
				if (j + 1 == i) {
					dp[i][j] = 1;
				}
				else {
					if (dp[i - 1][j + 1] == 1) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = 0;
					}
				}
			}
		}
	}
}
