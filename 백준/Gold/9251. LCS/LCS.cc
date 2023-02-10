#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001] = { 0 };

/*
	j   A C A Y K P   str1
	  0 1 2 3 4 5 6
i	0 0 0 0 0 0 0 0 
C	1 0 0 1 1 1 1 1
A	2 0 1 1 2 2 2 2
P	3 0 1 1 2 2 2 3
C	4 0 1 2 2 2 2 3
A	5 0 1 2 3 3 3 3
K	6 0 1 2 3 3 4 4
str2
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str2.size(); i++) {
		for (int j = 0; j < str1.size(); j++) {
			if (str1[j] == str2[i]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	cout << dp[str2.size()][str1.size()];
}