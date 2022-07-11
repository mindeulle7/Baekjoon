#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t, sum;
        cin >> t;
        if(i == 0)
        {
            sum = t;
        }
        else
        {
            sum = v[i-1] + t;
        }
        v.push_back(sum);
    }
    for (int i = 0; i < m; i++)
    {
        int m1, m2;
        cin >> m1 >> m2;
        if(m1 == 1)
        {
            cout << v[m2-1] << "\n";
        }
        else
        {
            cout << v[m2-1] - v[m1-2] << "\n";
        }
    }
    return 0;
}