#include <iostream>
#include <queue>
using namespace std;

int N, K;
int Move[] = {-1,1};

void solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> K;
  solve();
  
  return 0;
}

void solve(){
  int arr[100001] = {0};
  bool visit[100001] = {false};
  queue<int> q;
  q.push(N);
  visit[N] = true;
  while(!q.empty()){
    int current = q.front();
    if(current == K)  break;
    q.pop();
    int next = current * 2;
    if(0 <= next && next <= 100000){
      if(!visit[next]){
        q.push(next);
        visit[next] = true;
        arr[next] = arr[current];
      }
    }
    for(int i=0; i<2; i++){
      next = current + Move[i];
      if(0 <= next && next <= 100000){
        if(!visit[next]){
          q.push(next);
          visit[next] = true;
          arr[next] = arr[current] + 1;
        }
      }
    }
  }
  cout << arr[K];
}