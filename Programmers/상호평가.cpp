#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

char getGrade(float score){
    if(score >= 90.0)return 'A';
    else if(score >= 80.0)return 'B';
    else if(score >= 70.0)return 'C';
    else if(score >= 50.0)return 'D';
    else return 'F';
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i=0;i<scores.size();i++){
        float sum = 0;
        float avg;
        int m = 0;
        int n = 100;
        bool flag1 = false,flag2 = false;
        for(int j=0;j<scores[i].size();j++){
            sum += scores[j][i];
            if(m == scores[j][i])flag1=true;
            if(n == scores[j][i])flag2=true;
            m = max(scores[j][i],m);
            n = min(scores[j][i],n);
        }
        if(m == scores[i][i] && !flag1){
            sum -= m;
            avg = sum/(scores.size()-1);
        }else if(n == scores[i][i] && !flag2){
            sum -= n;
            avg = sum/(scores.size()-1);
        }else{
            avg = sum/scores.size();           
        }
        answer.push_back(getGrade(avg));
    }
    
    
    return answer;
}
