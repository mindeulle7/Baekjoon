#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> adjacency[2001];
bool flag = false;

void init();
void solve(int current, int cnt, int visit[]);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int visit[2001] = {false};
  init();
  solve(0, 1, visit);
  if(flag){
    cout << 1;
  }
  else{
    cout << 0;
  }
}

void init(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int j, k;
    cin >> j >> k;
    adjacency[j].push_back(k);
    adjacency[k].push_back(j);
  }
}

void solve(int current, int cnt, int visit[]){
  if(cnt == 5){
    flag = true;
    return;
  }
  else if(cnt == 1){
    for(int i=0; i<N; i++){
      if(flag){
        return;
      }
      current = i;
      visit[current] = true;
      for(int j=0; j<adjacency[current].size(); j++){
        int next = adjacency[current][j];
        visit[next] = true;
        solve(next, cnt + 1, visit);
      }
      visit[current] = false;
    }
  }
  else{
    for(int i=0; i<adjacency[current].size(); i++){
      if(flag){
        return;
      }
      int next = adjacency[current][i];
      if(!visit[next]){
        visit[next] = true;
        solve(next, cnt + 1, visit);
      }
    }
    visit[current] = false;
  }
}