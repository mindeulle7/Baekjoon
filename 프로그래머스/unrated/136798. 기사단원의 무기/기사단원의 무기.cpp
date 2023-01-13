#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> v(number);
    for(int i=1; i<=number; i++){
        int cnt =0;
        for(int j=1; j*j<= i; j++){
            if(i%j==0){
                if(j*j == i)    cnt++;
                else    cnt+=2;
            }
        }
        v[i-1] = cnt;
    }
    for(int i=0; i<number; i++){
        if(v[i]<= limit)    answer += v[i];
        else    answer += power;
    }
    return answer;
}