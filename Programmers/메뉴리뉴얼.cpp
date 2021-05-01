#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<string,int> map;

bool visit[11];
int max_menu[11];

void dfs(int num,int depth,int idx,string order,string res){
    if(num == depth){
        //cout << res << endl;
        map[res]++;
        max_menu[num] = max(max_menu[num],map[res]);
        return ;
    }
    for(int i=idx;i<order.size();i++){
        if(visit[i])continue;
        visit[i] = true;
        dfs(num,depth+1,i,order,res + order[i]);
        visit[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0;i<course.size();i++){
        for(int j=0;j<orders.size();j++){
            if(course[i] > orders[j].size())continue; // 조합을 만들 수 없음
            sort(orders[j].begin(),orders[j].end());
            dfs(course[i],0, 0,orders[j],"");
        }
    }
    
    for(auto elem : map){
        if(elem.second == max_menu[elem.first.size()] && map[elem.first] >= 2){
            //cout << elem.first << " " << elem.second << endl;
            answer.push_back(elem.first);
        }
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}
