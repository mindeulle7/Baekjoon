#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> pick;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    for (int i = 0; i < n - m; i++)
    {
        pick.push_back(0);
    }
    for (int i = 0; i < m; i++)
    {
        pick.push_back(1);
    }
    do
    {
        vector<int> picked;
        for (int i = 0; i < v.size(); i++)
        {
            if (pick[i] == 1)
            {
                picked.push_back(v[i]);
            }
        }
        sort(picked.begin(), picked.end());
        do
        {
            vector<int> temp;
            for(int j=0; j<picked.size(); j++)
            {
                temp.push_back(picked[j]);
            }
            res.push_back(temp);
        } while (next_permutation(picked.begin(), picked.end()));

    } while (next_permutation(pick.begin(), pick.end()));
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
