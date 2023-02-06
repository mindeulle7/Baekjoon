#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long dp[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i] = 1;
		}
		else if (i == 1) {
			dp[i] = 1;
		}
		else {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	cout << dp[n - 1];
}
