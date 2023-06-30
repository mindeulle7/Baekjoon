#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;

int N, L, R, sum, cnt;
bool flag;
int map[50][50];
bool visit[50][50];
int Move[4][2] = {
  {1,0}, {0,1}, {-1,0}, {0,-1}
};
vector<pair<int,int>> Union;

void init();
void solve();
void bfs(pair<int,int> start);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  solve();
}

void init(){
  cin >> N >> L >> R;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> map[i][j];
    }
  }
}

void solve(){
  int ans = 0;
  while(1){
    flag = true;
    memset(visit,false,sizeof(visit));
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(!visit[i][j]){
          Union.clear();
          sum =0, cnt =0;
          bfs(make_pair(i,j));
          for(int k=0; k<Union.size(); k++){
            map[Union[k].first][Union[k].second] = sum / cnt;
          }
        }
      }
    }
    if(flag)  break;
    else  ans++;
  }
  cout << ans++;
}

void bfs(pair<int,int> start){
  queue<pair<int,int>> q;
  q.push(start);
  Union.push_back(start);
  visit[start.first][start.second] = true;
  while(!q.empty()){
    pair<int,int> current = q.front();
    sum += map[current.first][current.second];
    cnt++;
    Union.push_back(make_pair(current.first,current.second));
    q.pop();
    for(int i=0; i<4; i++){
      pair<int,int> next = make_pair(current.first + Move[i][0], current.second + Move[i][1]);
      int diff = abs(map[current.first][current.second] - map[next.first][next.second]);
      if(0 <= next.first && next.first < N && 0 <= next.second && next.second < N){
        if(!visit[next.first][next.second] && L <= diff && diff <= R){
          flag = false;
          q.push(next);
          visit[next.first][next.second] = true;
        }
      }
    }
  }
}