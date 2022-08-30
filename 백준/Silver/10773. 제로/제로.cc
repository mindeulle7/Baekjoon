#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t != 0)
        {
            v.push_back(t);
        }
        else
        {
            v.pop_back();
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << sum;
    return 0;
}