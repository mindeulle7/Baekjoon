#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N, K, finish;
int building[1001];
int sum[1001];
int inDegree[1001];

void init();
void solve(vector<int> Edge[]);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  int T;
  cin >> T;
  for(int t=0; t<T; t++){
    cin >> N >> K;
    memset(sum,0,sizeof(sum));
    vector<int> Edge[1001];
    for(int i=1; i<=N; i++){
      cin >> building[i];
      sum[i] = building[i];
    }
    for(int i=0; i<K; i++){
      int start, end;
      cin >> start >> end;
      Edge[start].push_back(end);
      inDegree[end]++;
    }
    cin >> finish;
    solve(Edge);
    }
}

void solve(vector<int> Edge[]){
  // find isDegree -> 0
  queue<int> q;
  for(int i=1; i<=N; i++){
    if(inDegree[i] == 0){
      q.push(i);
    }
  }

  vector<int> arr;
  for(int i=1; i<=N; i++){
    if(q.empty()){
      cout << "error";
      return;
    }
    int current = q.front();
    q.pop();
    arr.push_back(current);
    for(int j=0; j<Edge[current].size(); j++){
      int next= Edge[current][j]; 
      inDegree[next]--;
      sum[next] = max(sum[next], sum[current] + building[next]);
      if(inDegree[next] == 0){
        q.push(next);
      }
    }
  }
  cout << sum[finish] << "\n";
}