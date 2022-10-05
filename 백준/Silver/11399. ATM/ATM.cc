#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int oldsum = 0, newsum = 0;
	for (int i = 0; i < v.size(); i++) {
		oldsum = oldsum + newsum;
		newsum = newsum + v[i];
	}
	oldsum = oldsum + newsum;
	cout << oldsum;
	return 0;
}