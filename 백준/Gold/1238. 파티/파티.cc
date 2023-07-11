#include <iostream>
#include <memory.h>
using namespace std;

#define INF 99999999
int N, M, meet;
int adjacency[1001][1001];
int ans[1001][1001];

void init();
void Dijkstra(int start);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  cin >> N >> M >> meet;
  int maximum = 0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      adjacency[i][j] = i == j ? 0 : INF;
    }
  }
  for(int i=0; i<M; i++){
    int point1, point2, cost;
    cin >> point1 >> point2 >> cost;
    adjacency[point1][point2] = cost;
  }
  for(int i=1; i<=N; i++){
      Dijkstra(i);
  }
  for(int i=1; i<=N; i++){
    int temp = ans[i][meet] + ans[meet][i];
    maximum = max(maximum, temp);
  }
  cout << maximum;
}

void Dijkstra(int start){
  int pick = start, minimum, index;
  int dist[N+1];
  int visit[N+1];
  memset(visit,false,sizeof(visit));
  for(int i=0; i<N; i++){
    minimum = INF;
    visit[pick] = true;
    for(int j=1; j<=N; j++){
      if(!i){
        dist[j] = adjacency[pick][j];
        if(!visit[j] && dist[j] < minimum){
          minimum = dist[j];
          index = j;
        }
      }
      else if(!visit[j]){
        dist[j] = min(dist[j], dist[pick] + adjacency[pick][j]);
        if(dist[j] < minimum){
          minimum = dist[j];
          index = j;
        }
      }
    }
    pick = index;
  }
  for(int i=1; i<=N; i++){
    ans[start][i] = dist[i];
  }
}