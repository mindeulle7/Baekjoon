#include <iostream>
using namespace std;

#define INF 1000000000

int N, S, length = INF;
int arr[100000];

void init();
void solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}

void init(){
    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    solve();
}

void solve(){
    int left = 0, right = 0, sum = 0;
    while(right < N){
        sum += arr[right];
        right++;
        if(S <= sum){
            while(S <= sum - arr[left]){
                sum -= arr[left];
                left++;
            }
            length = min(length, right - left);
        }
    }
    if(length == INF){
        cout << 0;
    }
    else{
        cout << length;
    }
}