#include <iostream>
using namespace std;

pair<int,int> item [101];
int dp[101][100001] = {0};
int N, K;

void init();
int solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);;
  init();
  cout << solve();
}

void init(){
  cin >> N >> K;
  for(int i=1; i<=N; i++){
    int weight, value;
    cin >> weight >> value;
    item[i].first = weight;
    item[i].second = value;
  }
}

int solve(){
  // item.first == weight , item.second == value
  for(int i=1; i<=N; i++){
    for(int j=1; j<=K; j++){
      if(0 <= j-item[i].first){
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-item[i].first] + item[i].second);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[N][K];
}