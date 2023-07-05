#include <iostream>
#include <string>
using namespace std;

void solve(string s);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    string s;
    cin >> s;
    solve(s);
  }
}

void solve(string s){
  int cnt = 1;
  int sum = 0;
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'O'){
      sum += cnt;
      cnt++;
    }
    else{
      cnt = 1;
    }
  }
  cout << sum << "\n";
}