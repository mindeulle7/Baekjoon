#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> v;
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	for (int i = 1; i <= v.size(); i++) {
		sum = sum + abs(v[i - 1] - i);
	}

	cout << sum;

	return 0;
}