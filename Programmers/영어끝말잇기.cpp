#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<string,bool> map;
    int num;
    int order = 1; 
    bool flag = false;
    for(int i=0;i<words.size();i++){
        num = (i % n)+1;
        order = (i / n)+1;
        if(i!=0){ // 끝말잇기 틀린 사람
            if(words[i-1][words[i-1].size()-1] != words[i][0]){
                flag = true;
                break;
            }
        }
        if(map[words[i]]){
            flag = true;
            break; // 이전에 등장한 단어
        }
        map[words[i]] = true;
    }   
    
    if(!flag){
        num = 0; order = 0;
    }
    answer.push_back(num);
    answer.push_back(order);

    return answer;
}
