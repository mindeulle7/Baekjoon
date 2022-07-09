#include <iostream>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while (cin >> n) {
        int tmp = 0;
        int cnt = 1;
        while(1)
        {
            tmp = tmp * 10 + 1;
            tmp %= n;
            if(tmp == 0)
            {
                cout << cnt << "\n";
                break;
            }
        }
    }
}
