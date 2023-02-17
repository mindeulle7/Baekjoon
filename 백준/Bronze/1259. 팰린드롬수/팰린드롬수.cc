#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	string rev_s;
	while (1) {
		cin >> s;
		if (s == "0") {
			break;
		}
		rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		if (rev_s == s) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}	
	}
}