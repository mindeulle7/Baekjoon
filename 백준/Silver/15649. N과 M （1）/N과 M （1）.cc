#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> n;
    vector<int> m;
    vector<vector<int>> res;
    int n_num, m_num;
    cin >> n_num >> m_num;
    for (int i = 0; i < n_num; i++)
    {
        n.push_back(i + 1);
    }
    for (int i = 0; i < n_num - m_num; i++)
    {
        m.push_back(0);
    }
    for (int i = 0; i < m_num; i++)
    {
        m.push_back(1);
    }
    
    do
    {
        vector<int> v;
        for (int i = 0; i < n.size(); i++)
        {
            if (m[i] == 1)
            {
                v.push_back(n[i]);
            }
        }
        
        sort(v.begin(),v.end());
        
        do
        {
            vector<int> temp;
            for (int i = 0; i < v.size(); i++)
            {
                temp.push_back(v[i]);
            }
            res.push_back(temp);
        } while (next_permutation(v.begin(), v.end()));
    
    } while (next_permutation(m.begin(), m.end()));
    
    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}