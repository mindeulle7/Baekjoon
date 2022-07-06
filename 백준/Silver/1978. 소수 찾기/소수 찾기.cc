#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, cnt =0;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int check=0;
        int a;
        cin >> a;
        for(int i=1; i<=a; i++)
        {
            if(a%i==0)
            {
                check ++;
            }
        }
        if(check ==2)
        {
            cnt++;
        }
    }
    cout << cnt;
}