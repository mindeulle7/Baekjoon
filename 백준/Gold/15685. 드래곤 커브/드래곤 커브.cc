#include <iostream>
#include <vector>
using namespace std;

int N;
int map[101][101] = {0};
int Move[4][2] = {
    {1,0}, {0,-1}, {-1,0}, {0,1}
};

vector<vector<int>> input;

void init();
int solve();
int square();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cout << solve();
}

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        vector<int> temp;
        for(int j=0; j<4; j++){
            int t;
            cin >> t;
            temp.push_back(t);
        }
        input.push_back(temp);
    }
}

int solve(){

    for(int i=0; i<input.size(); i++){
        vector<int> dragon;
        pair<int,int> start = make_pair(input[i][0],input[i][1]);
        map[start.second][start.first]++;
        int direction = input[i][2];
        int generation = input[i][3];
        pair<int,int> current = make_pair(start.first ,start.second);
        dragon.push_back(direction);
        for(int j=0; j<generation; j++){
            for(int k=dragon.size()-1; 0<=k; k--){
                direction = dragon[k];
                direction = direction + 1 > 3 ? 0 : direction + 1;
                dragon.push_back(direction);
            }
        }
        for(int j=0; j<dragon.size(); j++){
            current.first += Move[dragon[j]][0];
            current.second += Move[dragon[j]][1];
            map[current.second][current.first]++;
        }
    }

    return square();
}

int square(){
    int cnt = 0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(map[i][j]){
                if(map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}