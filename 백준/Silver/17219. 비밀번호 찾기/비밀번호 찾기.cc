#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> v;
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> um;
    for(int i=0; i<n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        um.insert(make_pair(s1,s2));
    }
    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(int i=0; i<v.size(); i++)
    {
        auto it = um.find(v[i]);
        if(it != um.end())
        {
            cout << it->second << "\n";
        }
    }
}