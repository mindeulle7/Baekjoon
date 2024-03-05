#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[8] = { 8,7,6,5,4,3,2,1 };
	int tmp[8];
	for (int i = 0; i < 8; i++) {
		cin >> tmp[i];
	}
	bool flag = true;
	for (int i = 0; i < 8; i++) {
		if (arr[i] != tmp[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "descending";
		return 0;
	}
	flag = true;
	sort(arr, arr + 8);
	for (int i = 0; i < 8; i++) {
		if (arr[i] != tmp[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "ascending";
	}
	else {
		cout << "mixed";
	}
}