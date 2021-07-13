#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float map[502];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i=1;i<=N;i++){
        float cnt = 0;
        float fail_num = 0;
        for(int j=0;j<stages.size();j++){
            if(stages[j] >= i)cnt++;
            if(stages[j] == i)fail_num++;
        }
        map[i] = fail_num/cnt;
    }
    

    vector<pair<float,int>> failure;
    for(int i=1;i<=N;i++){
        failure.push_back({-1.0*map[i],i});
    }
    
    sort(failure.begin(),failure.end());
    
    for(auto elem : failure)answer.push_back(elem.second);
    
    
    return answer;
}
