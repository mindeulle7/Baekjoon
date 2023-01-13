#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> rank;
    for(int i=0; i<score.size(); i++){
        if(i<k){
            rank.push_back(score[i]);
            sort(rank.begin(),rank.end());
            answer.push_back(rank[0]);
        }
        else{
            if(rank[0] < score[i]){
                rank.erase(rank.begin());
                rank.push_back(score[i]);
                sort(rank.begin(), rank.end());
            }
            answer.push_back(rank[0]);
        }
    }
    return answer;
}