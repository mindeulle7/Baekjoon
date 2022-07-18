#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
void dfs(int num, int index);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    dfs(1, 0);
}

void dfs(int num, int index)
{
    if (index == m)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[j] << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        for (int i = num; i <= n; i++)
        {
            arr[index] = i;
            dfs(i, index + 1);
        }
    }
}