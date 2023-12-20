#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int cnt = 0;
vector<vector<int>> res;
bool sign[9]; // > -> false , < -> true

void max_dfs(int index, bool visit[], vector<int> v){
    if(index == v.size()){
        vector<int> temp;
        for(int i=0; i<v.size(); i++){
            temp.push_back(v[i]);
        }
        res.push_back(temp);
        visit[v[index-1]] = false;
        return;
    }
    for(int i=9; 0<=i; i--){
        if(index == 0){
            v[index] = i;
            visit[i] = true;
            max_dfs(index+1, visit, v);
        }
        else{
            if(sign[index-1]){
                if(!visit[i] && v[index-1] < i){
                    visit[i] = true;
                    v[index] = i;
                    max_dfs(index+1, visit, v);
                }
            }
            if(!sign[index-1]){
                if(!visit[i] && v[index-1] > i){
                    visit[i] = true;
                    v[index] = i;
                    max_dfs(index+1, visit, v);
                }
            }
        }
    }
    if(index == 0){
        return;
    }
    else{
        visit[v[index-1]] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        char temp;
        cin >> temp;
        if (temp == '>')
        {
            sign[i] = false;
        }
        else
        {
            sign[i] = true;
        }
    }
    vector<int> v(k + 1);
    int index = 0;
    bool visit[10];
    memset(visit,false,sizeof(visit));
    max_dfs(index, visit, v);
    for(int i=0; i<k+1; i++){
        cout << res[0][i];
    }
    cout << "\n";
    for(int i=0; i<k+1; i++){
        cout << res[res.size()-1][i];
    }
    cout << "\n";
}
