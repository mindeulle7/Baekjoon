#include <iostream>
using namespace std;

long long dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				dp[j] = 1;
			}
			else if (j == 2) {
				dp[j] = 1;
			}
			else if (j == 3) {
				dp[j] = 1;
			}
			else if (j == 4) {
				dp[j] = 2;
			}
			else if (j == 5) {
				dp[j] = 2;
			}
			else {
				dp[j] = dp[j - 5] + dp[j - 1];
			}
		}
		cout << dp[n] << "\n";
	}
}