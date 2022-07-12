// #include <iostream>
// #include <vector>
// using namespace std;

// void pop(int &n, vector<int> v1, vector<int>&v2, vector<char> &v3);

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int n, cnt = 0;
//     vector<int> v;
//     vector<int> res;
//     vector<char> c;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int t;
//         cin >> t;
//         res.push_back(t);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         v.push_back(i);
//         c.push_back('+');
//         pop(cnt, res, v, c);
//     }
//     if (v.empty())
//     {
//         for (int i = 0; i < c.size(); i++)
//         {
//             cout << c[i] << "\n";
//         }
//     }
//     else
//         cout << "NO";
//     return 0;
// }

// void pop(int &n, vector<int> v1, vector<int>&v2, vector<char> &v3)
// {
//     while(v1[n] == v2[v2.size()-1])
//     {
//         v2.pop_back();
//         n++;
//         v3.push_back('-');
//     }
// }

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int recursion(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[10] = {0};
    int a, b, c;
    cin >> a >> b >> c;
    string s = to_string(a*b*c);
    for(int i=1; i<=s.size(); i++)
    {
        int t = stoi(s);
        arr[(t%recursion(i+1))/recursion(i)]++;
    }
    for(int i=0;i<10;i++)
    {
        cout << arr[i] << "\n";
    }
}

int recursion(int n)
{
    if(n==1)
    {
        return 1;
    }
    return 10*recursion(n-1);
}