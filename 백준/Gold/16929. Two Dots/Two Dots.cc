#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;

int N, M;
char map[50][50];
int res[50][50];
bool visit[50][50];
int Move[][2] = {
  {1,0}, {0,1}, {-1,0}, {0,-1}
};
bool flag = false;

void init();
void solve();
void bfs(int i, int j);

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  solve();
  if(flag)  cout << "Yes";
  else  cout << "No";
}

void init(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> map[i][j];
    }
  }
}

void solve(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(flag)  return;
      bfs(i,j);
    }
  }
}

void bfs(int i, int j){
  char start_char = map[i][j];
  memset(res,0,sizeof(res));
  memset(visit,false,sizeof(visit));
  pair<int,int> start = make_pair(i,j);
  stack<pair<int,int>> q;
  q.push(start);
  visit[start.first][start.second] = true;
  while(!q.empty()){
    pair<int,int> current = q.top();
    if(3 <= res[current.first][current.second]){
      for(int i=0; i<4; i++){
        if(start.first == current.first + Move[i][0] && start.second == current.second + Move[i][1]){
          flag = true;
          return;
        }
      }
    }
    visit[current.first][current.second] = true;
    q.pop();
    for(int i=0; i<4; i++){
      pair<int,int> next = make_pair(current.first + Move[i][0], current.second + Move[i][1]);
      if(0 <= next.first && next.first < N && 0 <= next.second && next.second < M){
        if(map[next.first][next.second] == start_char){
          if(!visit[next.first][next.second]){
            q.push(next);
            res[next.first][next.second] = res[current.first][current.second] + 1;
          }
        }
      }
    }
  }
}