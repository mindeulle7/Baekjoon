#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100000];

bool check(int *arr, int t, int n) {
	int first = 1;
	int last = n;
	while (first <= last) {
		int mid = (first + last) / 2;
		if (t == arr[mid])	return true;
		if (t < arr[mid]) {
			last = mid - 1;
		}
		else if (t > arr[mid]) {
			first = mid + 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (check(arr, t, n)) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
}