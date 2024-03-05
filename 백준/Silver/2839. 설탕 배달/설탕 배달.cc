#include <iostream>
using namespace std;

int N;

int main() {
	int res = 0;
	cin >> N;
	while (0 < N) {
		if (N % 5 == 0) {
			res += (N / 5);
			N = 0;
		}
		else {
			N -= 3;
			res++;
		}
	}
	if (N != 0) {
		cout << -1;
	}
	else {
		cout << res;
	}
}