#include <iostream>
#include <string>
using namespace std;

int five(int i) {
	int cnt = 0;
	while (i % 5 == 0) {
		i = i / 5;
		cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			cnt += five(i);
		}
	}
	cout << cnt;
}