#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
  int node1;
  int node2;
  int weight;
};

int V, E;
int parent[10001];
vector<node> v;

void init();
bool comp(node n1, node n2);
bool cycle(int n1, int n2);
int find_parent(int index);
void merge(int n1, int n2);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  cin >> V >> E;
  int N1, N2, W, sum = 0;
  for(int i=0; i<=V; i++){
    parent[i] = i;
  }
  for(int i=0; i<E; i++){
    cin >> N1 >> N2 >> W;
    node temp = {N1, N2, W};
    v.push_back(temp);
  }
  
  sort(v.begin(),v.end(), comp);

  for(int i=0; i<v.size(); i++){
    int n1 = v[i].node1;
    int n2 = v[i].node2;
    if(!cycle(n1,n2)){
      sum += v[i].weight;
      merge(n1,n2);
    }
  }
  cout << sum;
}

bool comp(node n1, node n2){
  return n1.weight < n2.weight;
}

bool cycle(int n1, int n2){
  if(find_parent(n1) == find_parent(n2)){
    return true;
  }
  else{
    return false;
  }
}

int find_parent(int node){
  if(parent[node] == node){
    return node;
  }
  else{
    return find_parent(parent[node]);
  }
}

void merge(int n1, int n2){
  n1 = find_parent(n1);
  n2 = find_parent(n2);
  if(n1 < n2){
    parent[n2] = n1;
  }
  else{
    parent[n1] = n2;
  }
}