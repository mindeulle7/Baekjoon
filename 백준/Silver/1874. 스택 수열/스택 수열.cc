#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> s;
	vector<char> c;
	vector<int> series;
	int n, t;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		series.push_back(t);
	}
	for (int i = 1; i <= n; i++) {
		s.push(i);
		c.push_back('+');
		while (1) {
			if (cnt == n) {
				break;
			}
			else if (s.empty()) {
				break;
			}
			else {
				if (s.top() == series[cnt]) {
					s.pop();
					c.push_back('-');
					cnt++;
				}
				else {
					break;
				}
			}
		}
	}
	if (s.empty()) {
		for (int i = 0; i < c.size(); i++) {
			cout << c[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}
}