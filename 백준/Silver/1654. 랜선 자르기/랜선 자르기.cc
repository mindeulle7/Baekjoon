#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> v, int mid, int n) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i] / mid;
	}
	if (sum < n) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v;
	int k, n, t;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	long long first = 1;
	long long last = v.back();
	long long mid;
	while (1) {
		if (last == first)	break;
		mid = (first + last) / 2;
		if (check(v, mid, n)) {
			if (first == mid) {
				break;
			}
			first = mid;
		}
		else {
			last = mid;
		}
	}
	if (check(v, last, n)) {
		cout << last;
	}
	else {
		cout << first;
	}
}
