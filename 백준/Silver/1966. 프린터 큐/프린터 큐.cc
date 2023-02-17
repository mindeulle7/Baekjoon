#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, n, m;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n >> m;
		int cnt = 0;
		vector<pair<int, int>> v;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			v.push_back(make_pair(t, j));
		}
		pair<int, int> temp = make_pair(-1, -1);
		while (1) {
			if (temp.second == m) {
				cout << cnt << "\n";
				break;
			}
			if (v.size() == 1) {
				temp = make_pair(v[0].first, v[0].second);
				cnt++;
			}
			else {
				bool flag = true;
				for (int j = 1; j < v.size(); j++) {
					if (v[0].first < v[j].first) {
						flag = false;
					}
				}
				if (flag) {
					temp = make_pair(v[0].first, v[0].second);
					cnt++;
					v.erase(v.begin());
				}
				else {
					v.push_back(v[0]);
					v.erase(v.begin());
				}
			}
		}
	}
}