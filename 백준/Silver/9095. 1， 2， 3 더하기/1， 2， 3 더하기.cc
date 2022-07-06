#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        int cur;
        int n_3 = 1, n_2 = 2, n_1 = 4; 
        if(n==1)
        {
            cout << "1\n";
            continue;
        }
        else if(n==2)
        {
            cout << "2\n";
            continue;
        }
        else if(n ==3)
        {
            cout << "4\n";
            continue;
        }
        else
        {
            for(int j=4; j<=n; j++)
            {
                cur = n_3 + n_2 + n_1;
                n_3 = n_2;
                n_2 = n_1;
                n_1 = cur;
            }
            cout << cur << "\n";
        }
    }
}