#include <iostream>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    multiset<int> s;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(t!=0){
            s.insert(t);
        }
        else{
            if(!s.empty()){
                auto iter = --(s.end());
                cout << *iter << "\n";
                s.erase(iter);
            }
            else{
                cout << "0\n";
            }
        }
    }
    return 0;
}