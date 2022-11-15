#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gap_(vector<int> v);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector<int> v;
		int gap;
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			v.push_back(t);
		}
		sort(v.begin(), v.end());
		gap = gap_(v);
		cout << "Class " << i + 1 << "\n";
		cout << "Max " << v[v.size() - 1] << ", Min " << v[0] << ", Largest gap " << gap << "\n";
	}
}

int gap_(vector<int> v) {
	int gap = 0;
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i + 1] - v[i] > gap) {
			gap = v[i + 1] - v[i];
		}
	}
	return gap;
}