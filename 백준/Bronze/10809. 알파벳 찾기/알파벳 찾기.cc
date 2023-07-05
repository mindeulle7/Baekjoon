#include <iostream>
#include <string>
using namespace std;

int character[200];
string s;

void init();
void solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  solve();
}

void init(){
  cin >> s;
  for(int i=0; i<200; i++){
    character[i] = -1;
  }
}

void solve(){
  for(int i=0; i<s.size(); i++){
    if(character[s[i]] == -1){
      character[s[i]] = i;
    }
  }
  for(int i='a'; i<='z'; i++){
    cout << character[i] << " ";
  }
}