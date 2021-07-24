#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> day;
    
    int d,r,elem;
    for(int i=0;i< progresses.size();i++){
        d = 100 - progresses[i];
        r = d % speeds[i];
        elem = d/speeds[i];
        if(r>0)elem++;
        day.push_back(elem);
    }
    
    int temp = day[0];
    int cnt = 1;
    for(int i=1;i<day.size();i++){
        if(day[i] > temp){
            temp = day[i];
            answer.push_back(cnt);
            cnt = 1;
        }else{    
            cnt++;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}
