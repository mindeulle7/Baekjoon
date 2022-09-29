#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int &a, int &b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t, p;
	vector<int> v;
	cin >> n >> t >> p;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	} // 처음에 점수들을 vector v에 입력
	if (n == 0) {
		cout << "1";
		return 0;
	} // n이 0이면 1을 출력하고 종료
	else if (v.size() == p && t <= v[p - 1]) {
		cout << "-1";
		return 0;
	} // v의 크기가 p 이고 입력받은 t가 vector 마지막 원소랑 같거나 작으면 -1
	else {
		v.push_back(t);
		sort(v.begin(), v.end(),compare); // vector의 크기가 p보다 작으면 t를 넣고 내림차순으로 정렬
		int k, cnt;
		if (v.size() > p) {
			k = p - 1;
			cnt = p+1;
		}
		else {
			k = v.size()-1;
			cnt = v.size()+1;
		} 
		while (0 <= k) {
			if (t < v[k]) {
				break;
			}
			k--;
			cnt--;
		}
		cout << cnt;
		return 0;
	}
}

bool compare(int &a, int &b) {
	return a > b;
}