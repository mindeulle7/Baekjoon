#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<double,double>> v;

void init();
void solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
}

void init(){
  cin >> N;
  for(int i=0; i<N; i++){
    double x, y;
    cin >> x >> y;
    v.push_back(make_pair(x,y));
  }
  v.push_back(v[0]);
  solve();
}

void solve(){
  double sum1 = 0, sum2 = 0;
  for(int i=0; i<v.size()-1; i++){
    sum1 += v[i].first * v[i+1].second;
    sum2 += v[i].second * v[i+1].first;
  }
  cout << fixed;
  cout.precision(1);
  cout << abs(sum1 - sum2) / 2;
}