#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int map[50][50];
bool visit[50][50];
int Move[4][2] ={
  {1,0}, {0,1}, {-1,0}, {0,-1}
};

void init();
void bfs(int M, int N, int row, int col);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  int T, M, N, K, row, col;
  cin >> T;
  for(int i=0; i<T; i++){
    int count = 0;
    memset(map,0,sizeof(map));
    memset(visit,false,sizeof(visit));
    cin >> M >> N >> K;
    for(int j=0; j<K; j++){
      cin >> row >>  col;
      map[row][col] = 1;
    }
    for(int j=0; j<M; j++){
      for(int k=0; k<N; k++){
        if(!visit[j][k] && map[j][k]){
          bfs(M, N, j, k);
          count++;
        }
      }
    }
    cout << count << "\n";
  }
}

void bfs(int M, int N, int row, int col){
  queue<pair<int,int>> q;
  q.push(make_pair(row,col));
  visit[row][col] = true;
  while(!q.empty()){
    pair<int,int> current = q.front();
    q.pop();
    for(int i=0; i<4; i++){
      int next_row = current.first + Move[i][0];
      int next_col = current.second + Move[i][1];
      if( 0 <= next_row && next_row < M && 0 <= next_col && next_col < N){
        if(!visit[next_row][next_col] && map[next_row][next_col]){
          pair<int,int> next = make_pair(next_row, next_col);
          q.push(next);
          visit[next.first][next.second] = true;
        }
      }
    }
  }
}