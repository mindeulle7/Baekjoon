#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n, m;
		cin >> n >> m;
		int cnt = 0;
		for (int j = n; j <= m; j++) {
			string s = to_string(j);
			for (int k = 0; k < s.size(); k++) {
				if (s[k] == '0') {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}