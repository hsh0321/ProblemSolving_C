//
//  순위검색.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/03/28.
//


#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string,unordered_map<string,unordered_map<string,unordered_map<string,vector<int>>>>> map;
    
    for(auto s : info){
        vector<string> result;
        string token;
        stringstream ss(s);
        while(getline(ss,token,' ')){
            result.push_back(token);
        }
        
        for(int i=0;i<(1<<4);i++){
            string tmp[4];
            for(int j=0;j<4;j++){
                tmp[j] = result[j];
            } // 초기화
            for(int j=0;j<4;j++){
                if((i & (1 << j)) > 0){
                    tmp[j] = "-";
                }
            }
            
            // for(int j=0;j<4;j++){
            //     cout << tmp[j] << ' ';
            // }
            // cout << endl;
            map[tmp[0]][tmp[1]][tmp[2]][tmp[3]].push_back(stoi(result[4]));
        }
    
        

        //cout << s << endl;
    }
    
    for(auto a : map){
        //cout << a.first << endl;
        for(auto b: map[a.first]){
            for(auto c : map[a.first][b.first]){
                for(auto d : map[a.first][b.first][c.first]){
                    sort(map[a.first][b.first][c.first][d.first].begin(),map[a.first][b.first][c.first][d.first].end());
                }
            }
            //cout << b.first << endl;
        }
    }
    
    for(auto q : query){
        vector<string> t;
        string token;
        stringstream ss(q);
        while(getline(ss,token,' ')){
            t.push_back(token);
        }
        
        int sum = 0;
        
        //sort(map[t[0]][t[2]][t[4]][t[6]].begin(),map[t[0]][t[2]][t[4]][t[6]].end());
        sum =  lower_bound(map[t[0]][t[2]][t[4]][t[6]].begin(),map[t[0]][t[2]][t[4]][t[6]].end(),stoi(t[7]))-map[t[0]][t[2]][t[4]][t[6]].begin();
        
        answer.push_back(map[t[0]][t[2]][t[4]][t[6]].size() - sum);
    }
    
    return answer;
}
