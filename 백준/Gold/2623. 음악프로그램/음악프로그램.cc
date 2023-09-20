#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int inDegree[1001];
int visit[1001];
vector<int> Edge[1001];
vector<int> ans;

void init();
bool solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  int start, end;
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int t;
    cin >> t;
    for(int j=0; j<t; j++){
      if(j==0){
        cin >> start;
      }
      else{
        cin >> end;
        Edge[start].push_back(end);
        inDegree[end]++;
        start = end;
      }
    }
  }
  if(solve()){
    for(int i=0; i<ans.size(); i++){
      cout << ans[i] << "\n";
    }
  }
  else{
    cout << 0;
  }
}

bool solve(){
  queue<int> q;
  for(int i=1; i<=N; i++){
    if(inDegree[i] == 0){
      q.push(i);
      visit[i] = true;
    }
  }
  for(int i=1; i<=N; i++){
    if(q.empty()){
      return false;
    }
    else{
      int current = q.front();
      q.pop();
      ans.push_back(current);
      for(int j=0; j<Edge[current].size(); j++){
        int next = Edge[current][j];
        inDegree[next]--;
        if(inDegree[next] == 0){
          q.push(next);
          visit[next] = true;
        }
      }
    }
  }
  return true;
}