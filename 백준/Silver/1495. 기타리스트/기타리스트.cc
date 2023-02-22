#include <iostream>
using namespace std;

int arr[1001];
int dp[51][1001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s, m;
	int max = -1;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			if (s + arr[i] <= m) {
				dp[i][s + arr[i]] = 1;
			}
			if (0 <= s - arr[i]) {
				dp[i][s - arr[i]] = 1;
			}
		}
		else {
			for (int j = 0; j <= m; j++) {
				if (dp[i - 1][j] == 1) {
					if (j + arr[i] <= m) {
						dp[i][j + arr[i]] = 1;
					}
					if (0 <= j - arr[i]) {
						dp[i][j - arr[i]] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i <= m; i++) {
		if (dp[n][i] == 1 && max < i) {
			max = i;
		}
	}
	if (max == -1) {
		cout << -1;
	}
	else {
		cout << max;
	}
}