#include <iostream>
#include <string>
using namespace std;

int n;
bool arr[21];

void input()
{
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "add")
        {
            int index;
            cin >> index;
            if (!arr[index])
            {
                arr[index] = true;
            }
        }
        else if (temp == "remove")
        {
            int index;
            cin >> index;
            if (arr[index])
            {
                arr[index] = false;
            }
        }
        else if (temp == "check")
        {
            int index;
            cin >> index;
            if (arr[index])
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (temp == "toggle")
        {
            int index;
            cin >> index;
            if (arr[index])
            {
                arr[index] = false;
            }
            else
            {
                arr[index] = true;
            }
        }
        else if (temp == "all")
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = true;
            }
        }
        else if (temp == "empty")
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    input();
}