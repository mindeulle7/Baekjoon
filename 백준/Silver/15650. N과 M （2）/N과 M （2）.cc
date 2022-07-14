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
    vector<int> v;
    vector<int> pick;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        v.push_back(i);
    }
    for(int i=0; i<m; i++)
    {
        pick.push_back(1);
    }
    for(int i=0; i<n-m; i++)
    {
        pick.push_back(0);
    }
    do
    {
        for(int i=0; i<v.size(); i++)
        {
            if(pick[i]==1)
            {
                cout << v[i] << " ";
            }
        }
        cout <<"\n";
    } while (prev_permutation(pick.begin(),pick.end()));
}