#include <iostream>
using namespace std;

int n, m;
int graph[101][101] = {0};
#define INF 9999999

void init();
void solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  solve();
}

void init(){
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int start, end, cost;
    cin >> start >> end >> cost;
    if(graph[start][end] == 0){
      graph[start][end] = cost;
    }
    else{
      graph[start][end] = min(graph[start][end],cost);
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i == j){
        graph[i][j] = 0;
      }
      else if(graph[i][j] == 0){
        graph[i][j] = INF;
      }
    }
  }
}

void solve(){
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        graph[i][j] = min(graph[i][j], graph[i][k]+ graph[k][j]);
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(graph[i][j] == INF){
        graph[i][j] = 0;
      }
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
}