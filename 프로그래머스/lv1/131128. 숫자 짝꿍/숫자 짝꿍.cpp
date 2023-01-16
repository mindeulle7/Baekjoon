#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(char a1, char a2){
    return a1 > a2;
}

bool check(string s){
    bool flag = false;
    for(int i=0; i<s.size(); i++){
        if(s[i] != '0') flag = true;
    }
    return flag;
}

string solution(string X, string Y) {
    string answer = "";
    int arr_x[10] = {0};
    int arr_y[10] = {0};
    for(int i=0; i<X.size(); i++){
        arr_x[X[i] - '0']++;
    }
    for(int i=0; i<Y.size(); i++){
        arr_y[Y[i] - '0']++;
    }
    string temp = "";
    for(int i=0; i<10; i++){
        if(arr_x[i] == 0 && arr_y[i])   continue;
        else{
            if(arr_x[i] <= arr_y[i]){
                for(int j=0; j<arr_x[i]; j++){
                    temp += to_string(i);
                }
            }
            else{
                for(int j=0; j<arr_y[i]; j++){
                    temp += to_string(i);
                }
            }
        }
    }
    if(temp.empty())    answer = "-1";
    else{
        sort(temp.begin(), temp.end(),comp);
        if(check(temp)) answer = temp;
        else    answer = "0";
    }
    return answer;
}