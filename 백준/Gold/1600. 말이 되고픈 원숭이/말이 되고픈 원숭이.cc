#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node{
  int row;
  int col;
  int horse;
};

int count = 0;
int K, W, H;
int graph[300][300];
int ans[300][300][50];
bool visit[300][300][50] = {false};
int monkey_move[4][2] ={
  {1,0}, {0,1}, {-1,0}, {0,-1}
};
int horse_move[8][2] ={
  {1,2}, {2,1}, {2,-1}, {1,-2},
  {-1,-2}, {-2,-1}, {-2,1}, {-1,2}
};

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
  cin >> K >> W >> H;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> graph[i][j];
      if(i == 0 && j == 0){
        for(int k=0; k<=K; k++){
          ans[i][j][k] = 0;
        }
      }
      else{
        for(int k=0; k<=K; k++){
          ans[i][j][k] = -1;
        }
      }
    }
  }
}

void solve(){
  queue<node> q;
  node start;
  start.row = 0;
  start.col = 0;
  start.horse = 0;
  q.push(start);
  visit[start.row][start.col][start.horse] = true;
  while(!q.empty()){
    node current = q.front();
    q.pop();
    // horse move
    for(int i=0; i<8; i++){
      node next;
      next.row = current.row + horse_move[i][0];
      next.col = current.col + horse_move[i][1];
      next.horse = current.horse + 1;
      if(next.horse <= K){
        if(0 <= next.row && next.row < H && 0 <= next.col && next.col < W && !graph[next.row][next.col]){
          if(!visit[next.row][next.col][next.horse]){
            q.push(next);
            visit[next.row][next.col][next.horse] = true;
            ans[next.row][next.col][next.horse] = ans[current.row][current.col][current.horse] + 1;
          }
        }
      }
    }
    // monkey move
    for(int i=0; i<4; i++){
      node next;
      next.row = current.row + monkey_move[i][0];
      next.col = current.col + monkey_move[i][1];
      next.horse = current.horse;
      if(0 <= next.row && next.row < H && 0 <= next.col && next.col < W && !graph[next.row][next.col]){
        if(!visit[next.row][next.col][next.horse]){
          q.push(next);
          visit[next.row][next.col][next.horse] = true;
          ans[next.row][next.col][next.horse] = ans[current.row][current.col][current.horse] + 1;
        }
      }
    }
  }

  int minimum = 9999999;
  for(int i=0; i<=K; i++){
    if(ans[H-1][W-1][i] != -1){
      minimum = min(minimum, ans[H-1][W-1][i]);
    }
  }
  if(minimum == 9999999){
    cout << -1;
  }
  else{
    cout << minimum;
  }
}