#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;

int K, V, E;
bool ans;
char group[20001];
bool visit[20001];

void init();
void dfs(int start, vector<int> adjacency[]);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  int node1, node2;
  cin >> K;
  for(int k=0; k<K; k++){
    cin >> V >> E;
    ans = true;
    memset(visit,false,sizeof(visit));
    vector<int> adjacency[20001];
    for(int i=0; i<E; i++){
      cin >> node1 >> node2;
      adjacency[node1].push_back(node2);
      adjacency[node2].push_back(node1);
    }
    if(V==1){
      cout << "NO\n";
      return;
    }
    for(int i=1; i<=V; i++){
      if(!visit[i]){
        dfs(i, adjacency);
      }
    }
    if(ans){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}

void dfs(int start, vector<int> adjacency[]){
  queue<int> s;
  s.push(start);
  visit[start] = true;
  group[start] = 'R';
  while(!s.empty()){
    int current = s.front();
    s.pop();
    for(int i=0; i<adjacency[current].size(); i++){
      int next = adjacency[current][i];
      if(!visit[next]){
        group[next] = group[current] == 'R' ? 'B' : 'R';
        visit[next] = true;
        s.push(next);
      }
      else if(group[next] == group[current]){
        ans = false;
        return;
      }
    }
  }
}
