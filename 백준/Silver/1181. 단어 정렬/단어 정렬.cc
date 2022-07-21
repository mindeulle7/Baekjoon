#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string &s1, string &s2);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    vector<string> v;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}

bool compare(string &s1, string &s2)
{
    if (s1.size() == s2.size())
    {
        return s1 < s2;
    }
    else
        return s1.size() < s2.size();
}