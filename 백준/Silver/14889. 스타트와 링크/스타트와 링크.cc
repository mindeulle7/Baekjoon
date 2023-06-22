#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[20][20];
vector<vector<int>> team1;
vector<vector<int>> team2;

void init(int n);
int solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    int n;
    cin >> n;
    init(n);
    cout << solve();
}

void init(int n){
    vector<int> v;
    vector<int> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
        v.push_back(i);
    }
    for(int i=0; i<n/2; i++){
        temp.push_back(1);
    }
    for(int i=0; i<n/2; i++){
        temp.push_back(0);
    }

    do{
        vector<int> t1;
        vector<int> t2;
        for(int i=0; i<v.size(); i++){
            if(temp[i] == 1){
                t1.push_back(v[i]);
            }
            else{
                t2.push_back(v[i]);
            }
        }
        team1.push_back(t1);
        team2.push_back(t2);
    }while(prev_permutation(temp.begin(),temp.end()));

}

int solve(){
    int res = 99999;
    for(int i=0; i<team1.size(); i++){
        int sum = 0;
        int sum2 = 0;
        for(int j=0; j<team1[0].size(); j++){
            for(int k=j+1; k<team1[0].size(); k++){
                sum += (arr[team1[i][j]][team1[i][k]] + arr[team1[i][k]][team1[i][j]]);
                sum2 += (arr[team2[i][j]][team2[i][k]] + arr[team2[i][k]][team2[i][j]]);
            }
        }
        int cal = abs(sum - sum2);
        if(cal < res){
            res = cal;
        }
    }
    return res;
}