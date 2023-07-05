#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

struct node{
  int row;
  int col;
  int wall;
};

int graph[1000][1000];
int ans[2][1000][1000];
int Move[4][2] = {
  {1,0}, {0,1}, {-1,0}, {0,-1}
};

void solve();
void bfs(int N, int M);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();

  return 0;
}

void solve(){
  int N, M;
  cin >> N >> M;

  for(int i=0; i<N; i++){
    string s;
    cin >> s;
    for(int j=0; j<s.size(); j++){
      graph[i][j] = s[j] - '0';
      if(i==0 && j==0){
        ans[0][i][j] = 0;
        ans[1][i][j] = 0;  
      }
      else{
        ans[0][i][j] = -1;
        ans[1][i][j] = -1;
      }
    }
  }
  bfs(N, M);
  return;
}

void bfs(int N, int M){
  bool visit[2][N][M];
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
        if(graph[next_row][next_col] && next_wall == 1){
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
  int minimum = 99999999;
  if(ans[0][N-1][M-1] != -1){
    minimum = ans[0][N-1][M-1];
  }
  if(ans[1][N-1][M-1] != -1){
    minimum = min(minimum, ans[1][N-1][M-1]);
  }

  if(minimum == 99999999){
    cout << -1;
  }
  else{
    cout << minimum + 1 ;
  }
  return ;
}