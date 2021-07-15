#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

char kakao_friends[8] = {'A','C','F','J','M','N','R','T'};
char photo_order[8];
bool visit[8];
unordered_map<char,int> map;
vector<string> d;

int answer = 0;



void dfs(int num,vector<string> data){
    if(num == 8){
        for(int i=0;i<d.size();i++){
            char a = d[i][0];
            char b = d[i][2];
            char op = d[i][3];
            int num = d[i][4]-'0';
            
            int dist = abs(map[a]-map[b])-1;
            switch(op){
                case '=':
                    if(dist != num)return;
                    break;
                case '>':
                    if(dist <= num)return;   
                    break;
                case '<':
                    if(dist >= num)return;                    
                    break;
            }
        }
        answer++;

    }
    for(int i=0;i<8;i++){
        if(visit[i])continue;
        visit[i] = true;
        photo_order[num] = kakao_friends[i];
        map[kakao_friends[i]] = num;
        dfs(num+1,data);
        visit[i] = false;
    }
}

int solution(int n, vector<string> data) { 
    answer = 0;
    for(int i=0;i<8;i++){
        visit[i] = false;
        photo_order[i] = ' ';
    }
    
    d=data;
    
    dfs(0,data);
    
    return answer;
}
