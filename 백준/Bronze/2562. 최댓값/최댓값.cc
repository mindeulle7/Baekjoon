#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    vector<int> temp;
    for(int i=0; i<9; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
        temp.push_back(n);
    }
    sort(temp.begin(), temp.end());
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]== temp[temp.size()-1])
        {
            cout << v[i] << "\n" << i+1;
        }
    }
}