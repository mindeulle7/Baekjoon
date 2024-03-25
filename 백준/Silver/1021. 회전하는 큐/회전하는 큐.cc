#include <iostream>
#include <deque>
#include <vector>
using namespace std;

deque<int> dq;

int main() {
	int n, m;
	int sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	
	for (int i = 0; i < m; i++) {
		int tmp;
		int left, right; 
		cin >> tmp;
		int start = dq.front();
		for (int j = 0; j < dq.size(); j++) {
			if (dq.front() == tmp) {
				left = j;
			}
			dq.push_back(dq.front());
			dq.pop_front();
		}
		for (int j = 0; j < dq.size(); j++) {
			if (dq.front() == tmp) {
				right = j;
			}
			dq.push_front(dq.back());
			dq.pop_back();
		}
		if (left < right) {
			sum += left;
			for (int j = 0; j < left; j++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
		}
		else {
			sum += right;
			for (int j = 0; j < right; j++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			dq.pop_front();
		}
	}
	cout << sum;
}
