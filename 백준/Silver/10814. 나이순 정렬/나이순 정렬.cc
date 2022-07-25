#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,string> &p1, const pair<int,string> &p2);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    vector<pair<int,string>> v;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int a;
        string s;
        cin >> a >> s;
        v.push_back(make_pair(a,s));
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";

    }

}

bool cmp(const pair<int,string> &p1, const pair<int,string> &p2)
{
    return (p1.first< p2.first);
}