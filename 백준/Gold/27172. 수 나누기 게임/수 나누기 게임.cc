#include <iostream>
#include <vector>
using namespace std;

int N;
int card[100001];
int ans[100001];
vector<int> divisor[1000001];

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
    for(int i=1; i<=N; i++){
        cin >> card[i];
        int number = card[i];
        for(int j=1; j*j<= number; j++){
            if(j*j==number){
                divisor[j].push_back(i);
            }
            else if(number%j==0){
                divisor[j].push_back(i);
                divisor[number/j].push_back(i);
            }
        }
    }
    solve();
}

void solve(){
    for(int i=1; i<=N; i++){
        for(int j=0; j<divisor[card[i]].size(); j++){
            ans[i]++;
            ans[divisor[card[i]][j]]--;
        }
    }
    for(int i=1; i<=N; i++){
        cout << ans[i] << " ";
    }
}
