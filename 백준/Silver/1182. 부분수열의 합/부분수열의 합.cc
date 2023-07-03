#include <iostream>
#include <vector>
using namespace std;

int N, S, count = 0;
vector<int> arr;

void init();
void solve(int index, int sum);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  solve(0,0);
  cout << count;
}

void init(){
  cin >> N >> S;
  for(int i=0; i<N; i++){
    int t;
    cin >> t; 
    arr.push_back(t);
  }
}

void solve(int index, int sum){
  if(index == N) return;
  if(sum + arr[index] == S) count++;

  solve(index+1, sum);
  solve(index+1, sum + arr[index]);
}