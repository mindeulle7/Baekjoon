#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2000000000

vector<long long> v;

void solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	long long  temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
  sort(v.begin(),v.end());
	solve();
}

void solve() {
	int point1 = 0;
	int point2 = v.size() - 1;
	long long minimum = INF;
	long long ans1 = v[point1], ans2 = v[point2];
	while (point1 != point2) {
		long long temp = v[point1] + v[point2];
		if (abs(temp) < minimum) {
			minimum = abs(temp);
			ans1 = v[point1];
			ans2 = v[point2];
		}
		if (temp > 0) {
			point2--;
		}
		else if (temp < 0) {
			point1++;
		}
		else {
			break;
		}
	}
	cout << ans1 << " " << ans2;
}