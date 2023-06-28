#include <iostream>
using namespace std;

int N, M;
long long adjacency[1001][1001];
long long dist[1001];
bool visit[1001] = {false};

void init();
int solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  cout << solve();
}

void init(){
  for(int i=0; i<1001; i++){
    for(int j=0; j<1001; j++){
      if(i==j){
        adjacency[i][j] == 0;
      }
      else{
        adjacency[i][j] = 10000000000;
      }
    }
    dist[i] = 10000000000;
  }
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int j, k;
    long long cost;
    cin >> j >> k >> cost;
    if(adjacency[j][k] == 10000000000){
      adjacency[j][k] = cost;
    }
    else{
      adjacency[j][k] = min(adjacency[j][k] , cost);
    }
  }
}

int solve(){
  int start, end;
  cin >> start >> end;
  if(start == end){
    return 0;
  }
  int pick = start;
  for(int i=0; i<N; i++){
    if(pick == end){
      break;
    }
    visit[pick] = true;
    int index;
    long long  minimum = 10000000000;
    for(int j=1; j<=N; j++){
      if(i==0){
        dist[j] = adjacency[pick][j];
        if(!visit[j] && dist[j] <= minimum){
          minimum = dist[j];
          index = j;
        }
      }
      else{
       dist[j] = min(dist[j], dist[pick] + adjacency[pick][j]);
        if(!visit[j] && dist[j] <= minimum){
          minimum = dist[j];
          index = j;
        } 
      }
    }
    pick = index;
  }
  return dist[end];
}