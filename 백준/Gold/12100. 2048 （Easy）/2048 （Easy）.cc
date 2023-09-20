#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, maximum;

void init();
void recursion(int graph[][21], int cnt);
void Move(int graph[][21], int number);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
}

void init(){  
  int graph[21][21];
  cin >> N;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cin >> graph[i][j];
    }
  }
  recursion(graph,0);
  cout << maximum;
}

void recursion(int graph[][21], int cnt){
  if(cnt == 5){
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        maximum = max(maximum, graph[i][j]);
      }
    }
    return;
  }
  else{
    for(int i=1; i<=4; i++){
      int temp[21][21];
      memcpy(temp, graph, sizeof(int) * 21 * 21);
      Move(temp,i);
      recursion(temp,cnt+1);
    }
  }
}

void Move(int graph[][21], int number){
  //Left
  if(number == 1){
    for(int i=1; i<=N; i++){
      deque<pair<int,int>> dq;
      int index = 1;
      for(int j=1; j<=N; j++){
        if(graph[i][j] != 0){
          if(dq.empty()){
            dq.push_back(make_pair(graph[i][j],0));
          }
          else{
            if(dq.back().first == graph[i][j] && dq.back().second == 0){
              dq.pop_back();
              dq.push_back(make_pair(graph[i][j] * 2,1));
            }
            else{
              dq.push_back(make_pair(graph[i][j],0));
            }
          }
        }
        graph[i][j] = 0;
      }
      while(!dq.empty()){
        graph[i][index] = dq.front().first;
        dq.pop_front();
        index++;
      }
    }
  }
  //Right
  else if(number == 2){
    for(int i=1; i<=N; i++){
      deque<pair<int,int>> dq;
      int index = N;
      for(int j=N; 0<j; j--){
        if(graph[i][j] != 0){
          if(dq.empty()){
            dq.push_back(make_pair(graph[i][j],0));
          }
          else{
            if(dq.back().first == graph[i][j] && dq.back().second == 0){
              dq.pop_back();
              dq.push_back(make_pair(graph[i][j] * 2,1));
            }
            else{
              dq.push_back(make_pair(graph[i][j],0));
            }
          }
        }
        graph[i][j] = 0;
      }
      while(!dq.empty()){
        graph[i][index] = dq.front().first;
        dq.pop_front();
        index--;
      }
    }
  }
  //Up
  else if(number == 3){
    for(int i=1; i<=N; i++){
      deque<pair<int,int>> dq;
      int index = 1;
      for(int j=1; j<=N; j++){
        if(graph[j][i] != 0){
          if(dq.empty()){
            dq.push_back(make_pair(graph[j][i],0));
          }
          else{
            if(dq.back().first == graph[j][i] && dq.back().second == 0){
              dq.pop_back();
              dq.push_back(make_pair(graph[j][i] * 2,1));
            }
            else{
              dq.push_back(make_pair(graph[j][i],0));
            }
          }
        }
        graph[j][i] = 0;
      }
      while(!dq.empty()){
        graph[index][i] = dq.front().first;
        dq.pop_front();
        index++;
      }
    }
  }
  else {
    for(int i=1; i<=N; i++){
      deque<pair<int,int>> dq;
      int index = N;
      for(int j=N; 0<j; j--){
        if(graph[j][i] != 0){
          if(dq.empty()){
            dq.push_back(make_pair(graph[j][i],0));
          }
          else{
            if(dq.back().first == graph[j][i] && dq.back().second == 0){
              dq.pop_back();
              dq.push_back(make_pair(graph[j][i] * 2,1));
            }
            else{
              dq.push_back(make_pair(graph[j][i],0));
            }
          }
        }
        graph[j][i] = 0;
      }
      while(!dq.empty()){
        graph[index][i] = dq.front().first;
        dq.pop_front();
        index--;
      }
    }
  }
}
