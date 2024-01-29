#include <iostream>
#include <string>
using namespace std;

bool flag[200];

int main() {
	string input;
	cin >> input;
	string s;
	string temp = "";
	int index = 0;
	
	for (int i = 0; i < input.size(); i++) {
		if (i == 0 || i == 1) {
			s.push_back(input[i]);
		}
		else {
			if (input[i] == '0') {
				if (s[s.size() - 2] == '0' && s[s.size() - 1] == '0') {
					continue;
				}
				else {
					s.push_back(input[i]);
				}
			}
			else {
				s.push_back(input[i]);
			}
		}
	}

	int token = s.find("00");
	flag[token - 1] = true;
	while (1) {
		token = s.find("00", token + 2, 2);
		if (token == string::npos) {
			break;
		}
		else {
			flag[token - 1] = true;
		}
	}
	while (index < s.size()) {
		if (temp.empty()) {
			temp.push_back(s[index]);
		}
		else if (temp == "1") {
			if (s[index] == '1') {
				cout << "NOISE";
				return 0;
			}
			else {
				temp.push_back(s[index]);
			}
		}
		else if (temp == "10") {
			if (s[index] == '1') {
				cout << "NOISE";
				return 0;
			}
			else {
				temp.push_back(s[index]);
			}
		}
		else if (temp == "100") {
			if (s[index] == '1') {
				if (!flag[index]) {
					temp.push_back(s[index]);
				}
				else {
					cout << "NOISE";
					return 0;
				}
			}
		}
		else if (temp == "1001") {
			if (s[index] == '0') {
				temp = "0";
			}
			else {
				if (flag[index]) {
					temp = "1";
				}
			}
		}
		else if (temp == "0") {
			if (s[index] == '0') {
				cout << "NOISE";
				return 0;
			}
			else {
				temp = "";
			}
		}
		index++;
	}
	if (temp == "1001" || temp.empty()) {
		cout << "SUBMARINE";
	}
	else {
		cout << "NOISE";
	}
}