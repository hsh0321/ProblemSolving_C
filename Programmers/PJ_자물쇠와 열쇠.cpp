#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int lockSize = 0;
    
    // 자물쇠 홈 개수
    for(int i=0;i<lock.size();i++){
        for(int j=0;j<lock.size();j++){
            if(!lock[i][j])lockSize++;
        }
    }
    
    
    for(int r=0;r<lock.size()+key.size()-1;r++){
        for(int c=0;c<lock.size()+key.size()-1;c++){
            bool isPossible[4] = {true,true,true,true};
            int num[4] = {0,0,0,0}; // 홈에 채운 개수
            for(int i=0;i<key.size();i++){
                for(int j=0;j<key.size();j++){
                    int tr = r-(key.size()-1)+i;
                    int tc = c-(key.size()-1)+j;
                    if(tr < 0 || tc < 0 || tr >= lock.size() || tc >= lock.size())continue;
                    if(key[i][j]==1 && lock[tr][tc] == 1)isPossible[0] = false; // 홈끼리 부딪힘
                    if(key[i][j]==1 && lock[tr][tc] == 0)num[0]++; // 구멍에 들어감
                    
                                        if(key[key.size()-1-j][i]==1 && lock[tr][tc] == 1)isPossible[1] = false; // 홈끼리 부딪힘
                    if(key[key.size()-1-j][i]==1 && lock[tr][tc] == 0)num[1]++; // 구멍에 들어감
                    
                                        if(key[key.size()-1-i][key.size()-1-j]==1 && lock[tr][tc] == 1)isPossible[2] = false; // 홈끼리 부딪힘
                    if(key[key.size()-1-i][key.size()-1-j]==1 && lock[tr][tc] == 0)num[2]++; // 구멍에 들어감
                    
                                        if(key[j][key.size()-1-i] ==1 && lock[tr][tc] == 1)isPossible[3] = false; // 홈끼리 부딪힘
                    if(key[j][key.size()-1-i] ==1 && lock[tr][tc] == 0)num[3]++; // 구멍에 들어감
                }
            }
            if(num[0] == lockSize && isPossible[0])return true;
            if(num[1] == lockSize && isPossible[1])return true;
            if(num[2] == lockSize && isPossible[2])return true;
            if(num[3] == lockSize && isPossible[3])return true;
        }
    }
    
    
    
    return false;
}
