#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, K;
int Move[2] = {-1, 1};

void solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}

void solve(){
  cin >> N >> K;
  int ans[100001];
  int cnt[100001];
  bool visit[100001];
  memset(ans,0,sizeof(ans));
  memset(cnt,0,sizeof(cnt));
  memset(visit,false,sizeof(visit));
  queue<int> q;
  q.push(N);
  visit[N] = true;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    int next = current * 2;
    if(0 <= next && next <= 100000){
      if(!visit[next]){
        q.push(next); 
        visit[next] = true;
        ans[next] = ans[current] + 1;
        cnt[next] = cnt[current];
      }
      else if(ans[next] == ans[current] + 1 ){
        cnt[next] += cnt[current] + 1;
      }
    }
    for(int i=0; i<2; i++){
      next = current + Move[i];
      if(0 <= next && next <= 100000){
        if(!visit[next]){
          q.push(next);
          visit[next] = true;
          ans[next] = ans[current] + 1;
          cnt[next] = cnt[current];
        }
        else if(ans[next] == ans[current] + 1){
          cnt[next] += cnt[current] + 1;
        }
      }
    }
  }
  cout << ans[K] << "\n" << cnt[K] + 1;
}

/*
  5 6 7 14 15 30 60 120 119 238 237
  5 4 8 16 15 30 60 120 119 238 237
  5 6 7 14 28 29 58 59  118 236 237
  5 4 8 16 15 30 60 59  118 236 237
  5 6 7 14 15 30 60 59  118 236 237
*/