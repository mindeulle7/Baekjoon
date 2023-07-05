#include <iostream>
using namespace std;

void solve(int hour, int minute);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int hour, minute;
  cin >> hour >> minute;
  solve(hour, minute);
}

void solve(int hour, int minute){
  minute -= 45;
  if(minute < 0){
    minute += 60;
    hour -= 1;
    if(hour < 0){
      hour = 23;
    }
    cout << hour << " " << minute;
  }
  else{
    cout << hour << " " << minute;
  }
}