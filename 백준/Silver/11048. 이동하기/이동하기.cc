#include <iostream>
using namespace std;
#define CON 1001

int dp[CON][CON], arr[CON][CON] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i][1] + dp[i - 1][1];
	}
	for (int i = 1; i <= m; i++) {
		dp[1][i] = dp[1][i] + dp[1][i - 1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
		}
	}
	cout << dp[n][m];
}