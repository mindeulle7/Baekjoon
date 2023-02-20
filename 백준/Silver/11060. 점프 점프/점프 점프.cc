#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, index, cnt;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 1) {
			dp[i] = 0;
		}
		else {
			dp[i] = -1;
		}
	}
	for (int i = 1; i < n; i++) {
		if (i == 1) {
			dp[i] = 0;
			index = i + 1;
			cnt = 0;
			while (cnt != arr[i]) {
				if (dp[index] == -1) {
					if (dp[i] == -1) {
						dp[index] = 1;
					}
					else {
						dp[index] = dp[i] + 1;
					}
				}
				else {
					int temp;
					if (dp[i] == -1) {
						temp = -2;
					}
					else {
						temp = dp[i];
					}
					dp[index] = min(dp[index], temp + 1);
				}
				cnt++;
				index++;
			}
		}
		else {
			index = i + 1;
			cnt = 0;
			while (cnt != arr[i]) {
				if (dp[index] == -1) {
					if (dp[i] == -1) {
						dp[index] = -1;
					}
					else {
						dp[index] = dp[i] + 1;
					}
				}
				else {
					int temp;
					if (dp[i] == -1) {
						temp = -2;
					}
					else {
						temp = dp[i];
					}
					dp[index] = min(dp[index], temp + 1);
				}
				cnt++;
				index++;
			}
		}
	}
	cout << dp[n];
}