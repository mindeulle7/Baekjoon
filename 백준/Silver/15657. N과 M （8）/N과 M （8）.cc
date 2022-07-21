#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
void dfs(int n, int index, vector<int> v, vector<int> &temp);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> temp(m);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    dfs(0, 0, v, temp);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int n, int index, vector<int> v, vector<int> &temp)
{
    if (n == temp.size())
    {
        sort(temp.begin(), temp.end());
        res.push_back(temp);
        return;
    }
    else
    {
        for (int i = index; i < v.size(); i++)
        {
            temp[n] = v[i];
            dfs(n + 1, i, v, temp);
        }
    }
}