#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	int i = 1;
	string res;
	while (1) {
		if (cnt == n) {
			break;
		}
		string s = to_string(i);
		if (s.find("666") != string::npos) {
			cnt++;
			res = s;
		}
		i++;
	}
	cout << res;
}