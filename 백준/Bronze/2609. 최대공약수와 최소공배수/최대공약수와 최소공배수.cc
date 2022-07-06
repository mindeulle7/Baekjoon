#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    int x, y;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            x = i;
        }
        
    }
    y = min(a, b);
    while(y % a != 0 || y % b != 0)
    {
        y += min(a,b);
    }
    cout << x << "\n"
         << y << "\n";
}