#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int R, C, T;
int map[50][50];
int machine[2];
int Move[4][2] = {
  {1,0}, {0,1}, {-1,0}, {0,-1}
};

void init();
void clean();
void clean_up();
void clean_down(); 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init(); 
}

void init(){
  cin >> R >> C >> T;
  int sum = 0;
  bool flag = true;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      cin >> map[i][j];
      if(map[i][j] == -1){
        if(flag){
          machine[0] = i;
          flag = false;
          map[i][j] = 0;
        }
        else{
          machine[1] = i;
          map[i][j] = 0;
        }
      }
    }
  }
  for(int i=0; i<T; i++){
    clean();
  }

  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      sum += map[i][j];
    }
  }

  cout << sum;
}

void clean(){
  vector<pair<int,int>> dust;
  int temp[50][50];
  memset(temp,0,sizeof(temp));
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(map[i][j]){
        dust.push_back(make_pair(i,j));
      }
    }
  }
  for(int i=0; i<dust.size(); i++){
    pair<int,int> point = dust[i];
    int dust_amount = map[point.first][point.second] / 5;
    int count = 0;
    for(int j=0; j<4; j++){
      int next_row = point.first + Move[j][0];
      int next_col = point.second + Move[j][1];
      if(0 <= next_row && next_row < R && 0 <= next_col && next_col < C){
        if((next_row == machine[0] && next_col == 0) || (next_row == machine[1] && next_col == 0)){
          continue;
        }
        temp[next_row][next_col] += dust_amount;
        count++;
      }
    }
    temp[point.first][point.second] += (map[point.first][point.second] - (count * dust_amount));
  }

  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      map[i][j] = temp[i][j];
    }
  }
  clean_up();
  clean_down();
}

void clean_up(){
  int row = machine[0];
  for(int i=row; 0<i; i--){
    swap(map[i][0],map[i-1][0]);
  }
  for(int i=0; i<C-1; i++){
    swap(map[0][i], map[0][i+1]);
  }
  for(int i=0; i<row; i++){
    swap(map[i][C-1], map[i+1][C-1]);
  }
  for(int i=C-1; 1<i; i--){
    swap(map[row][i],map[row][i-1]);
  }
  map[row][0] = 0;
}
void clean_down(){
  int row = machine[1];
  int sum = 0;
  for(int i=row; i<R-1; i++){
    swap(map[i][0], map[i+1][0]);
  }
  for(int i=0; i<C-1; i++){
    swap(map[R-1][i], map[R-1][i+1]);
  }
  for(int i=R-1; row < i; i--){
    swap(map[i][C-1], map[i-1][C-1]);
  }
  for(int i=C-1; 1<i; i--){
    swap(map[row][i], map[row][i-1]);
  }
  map[row][0] = 0;
}