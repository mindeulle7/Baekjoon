#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int arr[1000001];
bool visit[1000001] = {false};
int Move[2];

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
  cin >> F >> S >> G >> U >> D;
  for(int i=1; i<=F; i++){
    arr[i] = -1;
  }
  Move[0] = U;
  Move[1] = -D;
}

void solve(){
  queue<int> q;
  q.push(S);
  arr[S] = 0;
  visit[S] = true;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    for(int i=0; i<2; i++){
      int next = current + Move[i];
      if(1 <= next && next <= F){
        if(!visit[next]){
          q.push(next);
          visit[next]= true;
          arr[next] = arr[current] + 1;
        }
        else if(arr[current] + 1 < arr[next]){
          q.push(next);
          arr[next] = arr[current] + 1;
        }
      }
    }
  }
  if(arr[G] == -1){
    cout << "use the stairs";
  }
  else{
    cout << arr[G];
  }
}