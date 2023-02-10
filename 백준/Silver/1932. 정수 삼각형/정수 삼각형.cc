#include <iostream>
#include <algorithm>
using namespace std;

long long old_dp[501], arr[501], dp[501] = { 0, };


/*

       1            dp[1] = 1
     2   3          dp[1] = 3, dp[2] = 4
   4   5   6        dp[1] = 6, dp[2] = 9, dp[3] = 10 (2+5, 3+5 비교해서 더 큰 값을 dp 에 저장)
 1   2   1   2      dp[1] = 7, dp[2] = 11, dp[3] = 11 dp[4] = 12
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[j];
		}
		if (i == 1) {
			dp[i] = arr[i];
			old_dp[i] = dp[i];
		}
		else {
			for (int j = 1; j <= i; j++) {
				if (j == 1) {
					dp[j] = old_dp[j] + arr[j];
				}
				else {
					if (j == i) {
					dp[j] = old_dp[j - 1] + arr[j];
					}
					else {
					dp[j] = max(old_dp[j] + arr[j], old_dp[j - 1] + arr[j]);
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				old_dp[j] = dp[j];
			} 
		}
	}
	long long max_dp = 0;
	for (int i = 1; i <= n; i++) {
		if (max_dp < old_dp[i]) {
			max_dp = old_dp[i];
		}
	}
	cout << max_dp;
}
