#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    multiset<int> v;
    cin >> n;
    for(int i=0; i<n;i++)
    {
        int t;
        cin >> t;
        if(t!=0){
            v.insert(t);

        }
        else{
            if(!v.empty()){
                auto iter = v.begin();
                cout << *iter << "\n";
                v.erase(iter);
            }
            else{
                cout << "0" << "\n";
            }
        }
    }
}