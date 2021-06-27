#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> s;
int len;
bool check[8];

void dfs(vector<string>& u_id, vector<string>& b_id, int i, int num){
    if(i == len){
        s.insert(num);
        return;
    }
    
    for(int j = 0; j < u_id.size(); j++){
        if(u_id[j].size() != b_id[i].size())continue; // 다른 문자
        if(check[j] == true)continue; 

        int k;
        for(k = 0; k < u_id[j].size(); k++){
            if(b_id[i][k] == '*')continue;
            if(u_id[j][k] != b_id[i][k])break;
        }
        
        // 불량사용자
        if(k == u_id[j].size()){ 
            check[j] = true;
            dfs(u_id, b_id, i + 1, num | (1 << j));
            check[j] = false;     
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    len = banned_id.size();
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}
