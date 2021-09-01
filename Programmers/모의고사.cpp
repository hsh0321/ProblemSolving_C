#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s1 = {1,2,3,4,5};
vector<int> s2 = {2,1,2,3,2,4,2,5};
vector<int> s3 = {3,3,1,1,2,2,4,4,5,5};

int test(vector<int> answers, vector<int> submit){
    int numOfAnswer = 0;
    int idx = 0;
    for(int i=0;i<answers.size();i++){
        if(answers[i] == submit[i % submit.size()])
            numOfAnswer++;
    }
    
    return numOfAnswer;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int maxNum = 0;
    
    vector<int> scoreBoard;
    scoreBoard.push_back(test(answers,s1));
    scoreBoard.push_back(test(answers,s2));
    scoreBoard.push_back(test(answers,s3));
    
    maxNum = *max_element(scoreBoard.begin(),scoreBoard.end());
    
    for(int i=0;i<3;i++){
        if(maxNum == scoreBoard[i])
            answer.push_back(i+1);
    }
    
    return answer;
}
