#include <iostream>
using namespace std;

int dp[10001][3] = {0,};

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				dp[j][1] = 1;
				dp[j][2] = 0;
			}
			else if (j == 2) {
				dp[j][1] = 1;
				dp[j][2] = 1;
			}
			else if (j == 3) {
				dp[j][1] = 2;
				dp[j][2] = 1;
			}
			else {
				if (j % 3 == 0) {
					dp[j][1] = dp[j - 1][1] + dp[j - 1][2];
					dp[j][2] = dp[j - 2][2] + 1;
				}
				else {
					dp[j][1] = dp[j - 1][1] + dp[j - 1][2];
					dp[j][2] = dp[j - 2][2];
				}
			}
		}
		cout << dp[n][1] + dp[n][2] << "\n";
	}
}