#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const vector<int> v1, const vector<int> v2);
bool comp2( vector<int> v1, vector<int> v2);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<int>> v;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < 4; j++) {
			int t;
			cin >> t;
			temp.push_back(t);
		}
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),comp);
	int cnt = 0;
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i][0] == k) {
			cout << i + 1 - cnt;
			return 0;
		}
		if (comp2(v[i], v[i + 1])) {
			cnt++;
		}
		else {
			cnt = 0;
		}
	}
	cout << v.size() - cnt;
	return 0;
}

bool comp(const vector<int> v1, const vector<int> v2) {
	if (v1[1] == v2[1]) {
		if (v1[2] == v2[2]) {
			return v1[3] > v2[3];
		}
		else return v1[2] > v2[2];
	}
	else return v1[1] > v2[1];
}

bool comp2( vector<int> v1, vector<int> v2) {
	for (int i = 1; i < v1.size(); i++) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}