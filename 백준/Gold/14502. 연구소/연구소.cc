#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M, maximum = -1;
int map[8][8];
int Move[4][2] = {
  {1,0}, {0,1}, {-1,0}, {0,-1}
};

void init();
void bfs(vector<pair<int,int>> v);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  vector<pair<int,int>> v;
  vector<int> temp;
  vector<vector<pair<int,int>>> permu;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> map[i][j];
      if(map[i][j] == 0){
        v.push_back(make_pair(i,j));
      }
    }
  }
  for(int i=0; i<v.size()-3; i++){
    temp.push_back(0);
  }
  for(int i=0; i<3; i++){
    temp.push_back(1);
  }
  do{
    vector<pair<int,int>> temp2;
    for(int i=0; i<v.size(); i++){
      if(temp[i] == 1){
        temp2.push_back(v[i]);
      }
    }
    permu.push_back(temp2);
  }while(next_permutation(temp.begin(),temp.end()));

  for(int i=0; i<permu.size(); i++){
    bfs(permu[i]);
  }
  cout << maximum;
}

void bfs(vector<pair<int,int>> v){
  pair<int,int> start;
  int cnt = 0;
  bool visit[8][8];
  int temp[8][8];
  memset(visit,false,sizeof(visit));
  memset(temp,0,sizeof(temp));
  for(int i=0; i<v.size(); i++){
    temp[v[i].first][v[i].second] = 1;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(!temp[i][j]){
        temp[i][j] = map[i][j];
        if(temp[i][j] == 2){
          start = make_pair(i,j);
        }
      }
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(temp[i][j] == 2 && !visit[i][j]){
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        visit[i][j] = true;
        while(!q.empty()){
          pair<int,int> current = q.front();
          q.pop();
          for(int i=0; i<4; i++){
            int next_row = current.first + Move[i][0];
            int next_col = current.second + Move[i][1];
            if(0 <= next_row && next_row < N && 0 <= next_col && next_col < M && temp[next_row][next_col] != 1){
              if(!visit[next_row][next_col]){
                q.push(make_pair(next_row,next_col));
                visit[next_row][next_col] = true;
                temp[next_row][next_col] = 2;
              }
            }
          }
        }
      }
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(temp[i][j] == 0){
        cnt++;
      }
    }
  }
  maximum = max(maximum,cnt);
}