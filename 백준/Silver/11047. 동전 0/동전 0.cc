#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, cnt = 0;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end(),greater<>()); // 입력받은 동전의 가치를 내림차순으로 정렬
	for (int i = 0; i < v.size(); i++) {
		// 동전의 가치가 입력받은 k보다 작을 시 k / 동전의 가치 만큼 k에 빼주고 다시 k 값 초기화
		if (v[i] <= k) {
			cnt = cnt + (k / v[i]);
			k = k - ((k / v[i]) * v[i]);
		}
	}
	cout << cnt;
	return 0;
}