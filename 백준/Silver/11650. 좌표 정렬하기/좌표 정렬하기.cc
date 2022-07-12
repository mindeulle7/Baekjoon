#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> v;
    int n;
    cin>> n;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        int a , b;
        cin>> a >> b;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}