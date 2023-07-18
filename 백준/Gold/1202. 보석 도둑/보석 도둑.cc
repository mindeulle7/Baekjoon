#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <set>
using namespace std;

#define MAX 300001

struct jewel
{
  int weight;
  int price;
};

vector<jewel> jewels;
vector<int> bag;
priority_queue<int> pq;

void solve(int N, int K);
bool cmp(jewel j1, jewel j2);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K, weight, price;
  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> weight >> price;
    jewel temp = {weight, price};
    jewels.push_back(temp);
  }
  for (int i = 0; i < K; i++)
  {
    cin >> weight;
    bag.push_back(weight);
  }
  sort(jewels.begin(),jewels.end(),cmp);
  sort(bag.begin(), bag.end());
  solve(N,K);
  
}


void solve(int N, int K)
{
  long long sum = 0;
  int index = 0;
  for(int i=0; i<K; i++){
    while(index < N && jewels[index].weight <= bag[i]){
      pq.push(jewels[index].price);
      index++;
    }
    if(!pq.empty()){
      sum += pq.top();
      pq.pop();
    }
  }
  cout << sum;
}

bool cmp(jewel j1, jewel j2){
  return j1.weight < j2.weight;
}
