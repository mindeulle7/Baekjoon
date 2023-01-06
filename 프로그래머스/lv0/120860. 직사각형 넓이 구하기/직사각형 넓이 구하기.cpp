#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    sort(dots.begin(), dots.end());
    int y = abs(dots[0][1] - dots[1][1]);
    int x = abs(dots[1][0]-dots[2][0]);
    answer = x*y;
    return answer;
}