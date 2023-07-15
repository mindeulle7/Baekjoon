#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int inDegree[32001];
vector<int> ans;

void init();
void topological_sort(vector<int> v[]);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  cin >> N >> M;
  int start, end;
  vector<int> v[N+1];
  for(int i=0; i<M; i++){
    cin >> start >> end;
    v[start].push_back(end);
    inDegree[end]++;
  }
  topological_sort(v);
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }
}

void topological_sort(vector<int> v[]){
  queue<int> q;
  for(int i=1; i<=N; i++){
    if(inDegree[i] == 0){
      q.push(i);
    }
  }
  for(int i=1; i<=N; i++){
    if(q.empty()){
      return;
    }
    int current = q.front();
    q.pop();
    ans.push_back(current);
    for(int j=0; j<v[current].size(); j++){
      int next = v[current][j];
      inDegree[next]--;
      if(inDegree[next] == 0){
        q.push(next);
      }
    }
  }
}
