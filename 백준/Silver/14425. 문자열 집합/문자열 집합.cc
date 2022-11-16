#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, cnt = 0;
	cin >> n >> m;
	map<string,int> map_s;
	//hash algorithm를 사용해서 품.
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		pair<string,int> p;
		p.first = t;
		p.second = i;
		map_s.insert(p);
		// or map_s.insert(pair<string,int>(t,i));
	}
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		if (map_s.find(t) != map_s.end()) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}