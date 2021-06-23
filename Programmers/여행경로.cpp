#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<string,vector<string>> map;
unordered_map<string,int> visit;

vector<string> answer;

int num_tickets;

void dfs(int num,string src,vector<string> v){
    if(num == num_tickets){
        for(auto elem : v){
            answer.push_back(elem);
        }
        return;
    }
    for(int i=0;i<map[src].size();i++){
        string dst = map[src][i];
        if(visit[src+dst] == 0)continue; // 사용한 항공권
        visit[src+dst]--;
        v.push_back(dst);
        dfs(num+1,dst,v);
        v.pop_back();
        if(answer.size() != 0)return;
        visit[src+dst]++;
    }
}


vector<string> solution(vector<vector<string>> tickets) {

    num_tickets = tickets.size(); 
    
    
    for(int i=0;i<tickets.size();i++){
        map[tickets[i][0]].push_back(tickets[i][1]);
        visit[tickets[i][0] + tickets[i][1]]++;
    }
    
    for(auto &elem : map){
        sort(elem.second.begin(),elem.second.end());
    }

    vector<string> v;
    v.push_back("ICN");
    dfs(0,"ICN",v);
    
    return answer;
}
