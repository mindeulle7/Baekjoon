#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long x, y, w, s;
	cin >> x >> y >> w >> s;
	long long sum = 0;
	if (2 * w < s) {
		sum = 2 * w * min(x, y);
	}
	else {
		sum = s * min(x, y);
	}

	int gap = max(x, y) - min(x, y);
	if (gap % 2 == 0) {
		if (w < s) {
			sum = sum + gap * w;
		}
		else {
			sum = sum + gap * s;
		}
	}
	if (gap % 2 == 1) {
		if (w < s) {
			sum = sum + gap * w;
		}
		else {
			sum = sum + (gap / 2) * 2 * s + w;
		}
	}
	cout << sum;
}