#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
void dfs(int n, vector<int> v, vector<int> &temp);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> temp(m, 0);
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    dfs(0, v, temp);
    sort(res.begin(),res.end());
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int n, vector<int> v, vector<int> &temp)
{
    if (n == temp.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        temp[n] = v[i];
        dfs(n + 1, v, temp);
    }
}