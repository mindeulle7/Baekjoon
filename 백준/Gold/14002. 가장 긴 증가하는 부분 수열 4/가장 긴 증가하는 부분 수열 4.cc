#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0, };
int dp[1001][1001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dp[i][1] = 1;
			dp[i][2] = arr[i];
		}
		else {
			int idx = 2;
			dp[i][1] = 1;
			dp[i][2] = arr[i];
			for (int j = 1; j < i; j++) {
				int index, max_dp = -1;
				if (arr[j] < arr[i]) {
					if (dp[i][1] < dp[j][1] + 1) {
						dp[i][1] = dp[j][1] + 1;
						idx = 2;
						while (dp[j][idx] != 0) {
							dp[i][idx] = dp[j][idx];
							idx++;
						}
						dp[i][idx] = arr[i];
					}
				}
				if (max_dp < dp[j][1]) {
					max_dp = dp[j][1];
					index = j;
				}
			}
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n + 1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	int index, max_dp = -1;
	for (int i = 1; i <= n; i++) {
		if (max_dp < dp[i][1]) {
			max_dp = dp[i][1];
			index = i;
		}
	}
	cout << dp[index][1] << "\n";
	for (int i = 2; i <= dp[index][1]+1; i++) {
		cout << dp[index][i] << " ";
	}
	cout << "\n";

}
