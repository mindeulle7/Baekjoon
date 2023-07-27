#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct planet{
  int p1;
  int p2;
  int dist;
};

int N;
int parent[100001];

vector<pair<int,int>> v_x;
vector<pair<int,int>> v_y;
vector<pair<int,int>> v_z;
vector<planet> Edge;

bool cmp(pair<int,int> p1, pair<int,int> p2);
bool cmp2(planet p1, planet p2);
void solve();
int find_parent(int node);
bool Cycle(int node1, int node2);
void merge(int node1, int node2);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for(int i=0; i<N; i++){
    int x, y, z;
    cin >> x >> y >> z;
    v_x.push_back(make_pair(x,i));
    v_y.push_back(make_pair(y,i));
    v_z.push_back(make_pair(z,i));
    parent[i] = i;
  }
  sort(v_x.begin(), v_x.end(), cmp);
  sort(v_y.begin(), v_y.end(), cmp);
  sort(v_z.begin(), v_z.end(), cmp);

  solve();

}

bool cmp(pair<int,int> p1, pair<int,int> p2){
  return p1.first < p2.first;
}

bool cmp2(planet p1, planet p2){
  return p1.dist < p2.dist;
}

void solve(){
    int sum = 0;

    for(int i=0; i<N-1; i++){
    int p1, p2, dist;
    p1 = v_x[i].second;
    p2 = v_x[i+1].second;
    dist = abs(v_x[i].first - v_x[i+1].first);
    planet temp = {p1, p2, dist};
    Edge.push_back(temp);
    
    p1 = v_y[i].second;
    p2 = v_y[i+1].second;
    dist = abs(v_y[i].first - v_y[i+1].first);
    temp = {p1, p2, dist};
    Edge.push_back(temp);

    p1 = v_z[i].second;
    p2 = v_z[i+1].second;
    dist = abs(v_z[i].first - v_z[i+1].first);
    temp = {p1, p2, dist};
    Edge.push_back(temp);
  }

  sort(Edge.begin(), Edge.end(), cmp2);

  for(int i=0; i<Edge.size(); i++){
    int Planet1 = Edge[i].p1;
    int Planet2 = Edge[i].p2;
    int dist = Edge[i].dist;
    if(!Cycle(Planet1, Planet2)){
      sum += dist;
      merge(Planet1, Planet2);
    }
  }
  cout << sum;
}

int find_parent(int node){
  if(parent[node] == node){
    return node;
  }
  else{
    return find_parent(parent[node]);
  }
}

bool Cycle(int node1, int node2){
  if(find_parent(node1) == find_parent(node2)){
    return true;
  }
  else{
    return false;
  }
}
void merge(int node1, int node2){
  node1 = find_parent(node1);
  node2 = find_parent(node2);
  if(node1 < node2){
    parent[node2] = node1;
  }
  else{
    parent[node1] = node2;
  }
}