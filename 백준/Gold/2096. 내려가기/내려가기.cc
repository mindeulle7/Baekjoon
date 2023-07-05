#include <iostream>
using namespace std;

#define INF 9999999

int N;
int current[3];
int arr_max[2][3];
int arr_min[2][3];
int Move[] = {-1, 0, 1};

void solve_max();
void solve_min();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      cin >> current[j];
    }
    if(i==0){
      for(int k=0; k<3; k++){
        arr_max[0][k] = current[k];
        arr_min[0][k] = current[k];
        arr_max[1][k] = 0;
        arr_min[1][k] = INF;
      }
      continue;
    }
    else{
      solve_max();
      solve_min();
    }
  }

  int maximum = 0;
  int minimum = INF;

  for(int i=0; i<3; i++){
    maximum = max(maximum, arr_max[0][i]);
    minimum = min(minimum, arr_min[0][i]);
  }
  cout << maximum << " " << minimum ;
}

void solve_max(){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      int next = i + Move[j];
      if(0 <= next && next < 3){
        arr_max[1][next] = max(arr_max[1][next], arr_max[0][i] + current[next]);
      }
    }
  } 
  for(int i=0; i<3; i++){
    arr_max[0][i] = arr_max[1][i];
    arr_max[1][i] = 0;
  }
}

void solve_min(){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      int next = i + Move[j];
      if(0 <= next && next < 3){
        arr_min[1][next] = min(arr_min[1][next], arr_min[0][i] + current[next]);
      }
    }
  } 
  for(int i=0; i<3; i++){
    arr_min[0][i] = arr_min[1][i];
    arr_min[1][i] = INF;
  }
}