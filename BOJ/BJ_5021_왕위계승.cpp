//
//  BJ_5021_왕위계승.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/18.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string king;

unordered_map<string, vector<string>> map;
unordered_map<string, bool> candidate;
unordered_map<string, float> val;

string answer;

void dfs(int num,string cur,float blood){
    val[cur] += blood;
    for(int i=0;i<map[cur].size();i++){
        dfs(num++,map[cur][i],blood * 0.5);
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    
    cin >> king;
    
    string child,parent1,parent2;
    for(int i=0;i<N;i++){
        cin >> child >> parent1 >> parent2;
        map[parent1].push_back(child);
        map[parent2].push_back(child);
    }
    
    string c;
    for(int i=0;i<M;i++){
        cin >> c;
        candidate[c] = true;
    }
    
    dfs(0,king,1);
    
    float temp = 0;
    for(auto &elem : val){
        if(candidate[elem.first] && elem.second > temp){
            answer = elem.first;
            temp = elem.second;
        }
    }

    cout << answer << endl;
    return 0;
}
