#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

#define INF 99999999

struct node{
  int row;
  int col;
  int wall;
};

int graph[1000][1000];
int ans[11][1000][1000];
int Move[4][2] = {
  {1,0}, {0,1}, {-1,0}, {0,-1}
};

void solve();
void bfs(int N, int M, int K);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();

  return 0;
}

void solve(){
  int N, M, K;
  cin >> N >> M >> K;
  memset(ans,-1,sizeof(ans));
  for(int i=0; i<N; i++){
    string s;
    cin >> s;
    for(int j=0; j<s.size(); j++){
      graph[i][j] = s[j] - '0';
      if(i==0 && j==0){
        for(int k=0; k<=K; k++){
          ans[k][i][j] = 0;
        }
      }
    }
  }
  bfs(N, M, K);
  return;
}

void bfs(int N, int M, int K){
  bool visit[11][N][M];
  memset(visit,false,sizeof(visit));
  queue<node> q;
  node start = {0, 0, 0};
  q.push(start);
  visit[0][0][0] = true;
  while(!q.empty()){
    node current = q.front();
    q.pop();
    for(int i=0; i<4; i++){
      int next_row = current.row + Move[i][0];
      int next_col = current.col + Move[i][1];
      int next_wall = current.wall + 1;
      if(0 <= next_row && next_row < N && 0 <= next_col && next_col < M){
        if(!graph[next_row][next_col] && !visit[current.wall][next_row][next_col]){
          node temp = {next_row, next_col, current.wall};
          q.push(temp);
          visit[current.wall][next_row][next_col] = true;
          ans[current.wall][next_row][next_col] = ans[current.wall][current.row][current.col] + 1;
        }
        if(graph[next_row][next_col] && next_wall <= K){
          if(!visit[next_wall][next_row][next_col]){
            node temp = {next_row, next_col, next_wall};
            q.push(temp);
            visit[next_wall][next_row][next_col] = true;
            ans[next_wall][next_row][next_col] = ans[current.wall][current.row][current.col] + 1;
          }
        }
      }
    }
  }
  int minimum = INF;
  for(int i=0; i<=K; i++){
    if(ans[i][N-1][M-1] != -1){
      minimum = min(minimum, ans[i][N-1][M-1]);
    }
  }

  if(minimum == INF){
    cout << -1;
  }
  else{
    cout << minimum + 1 ;
  }
  return ;
}