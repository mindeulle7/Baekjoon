#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m, n, x, y;
        int a = 1, b = 1;
        cin >> m >> n >> x >> y;
        if (x == y)
        {
            cout << x << "\n";
        }
        else if (x < y)
        {
            int mul = 1;
            a = x;
            b = x;
            for (;;)
            {
                b += m;
                while (n < b)
                {
                    b -= n;
                }
                if (b == x)
                {
                    cout << "-1"
                         << "\n";
                    break;
                }
                else if (b == y)
                {
                    cout << ((mul * m) + x) << "\n";
                    break;
                }
                mul++;
            }
        }
        else
        {
            int mul = 1;
            a = y;
            b = y;
            for (;;)
            {
                a += n;
                while (m < a)
                {
                    a -= m;
                }
                if (a == y)
                {
                    cout << "-1"
                         << "\n";
                    break;
                }
                else if (a == x)
                {
                    cout << ((mul * n) + y) << "\n";
                    break;
                }
                mul++;
            }
        }
    }
}
