#include <string>
#include <vector>

using namespace std;


int visit[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zero_cnt =0; // 0의 개수
    int correct_cnt = 0; // 맞은 개수
    
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0){
            zero_cnt++;
            continue;
        }
        for(int j=0;j<win_nums.size();j++){
            if(visit[win_nums[j]])continue;
            if(lottos[i] == win_nums[j]){ // 로또번호 일치
                visit[win_nums[j]] = true;
                correct_cnt++;
                break;
            }
        }
    }
    answer.push_back(7-(correct_cnt + zero_cnt) <= 6 ? 7-(correct_cnt+zero_cnt) : 6);
    answer.push_back(7-correct_cnt <= 6 ? 7-correct_cnt : 6);
    
    return answer;
}
