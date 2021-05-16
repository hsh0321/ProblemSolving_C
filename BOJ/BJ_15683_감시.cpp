//
//  BJ_15683_감시.cpp
//  Algorithm
//
//  Created by 황성현 on 2021/03/22.
//

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n,m;
int map[9][9];
bool visit[8];
vector<pair<int,int>> cctv; // y,x

int dx[4] = {0,1,0,-1},dy[4] = {-1,0,1,0};
int rotateNum[5] = {4,2,4,4,1};
vector<int> arrow[5] = {{1},{1,3},{0,1},{0,1,3},{0,1,2,3}};

int answer;

int draw(int depth,int dir){
    pair<int,int> cur = cctv[depth];
    cur.first += dy[dir];
    cur.second += dx[dir];
    int cnt = 0; // 넓힌 시야의 개수
    while((cur.first >= 0 && cur.first < n && cur.second >= 0 && cur.second < m) && (map[cur.first][cur.second] != 6)){
        if(map[cur.first][cur.second] == 0){
            cnt++;
            map[cur.first][cur.second] = 9;
        }
        cur.first += dy[dir];
        cur.second += dx[dir];
    }
    return cnt;
}


void dfs(int depth,int areaNum){
    if(depth == cctv.size()){
        answer = min(answer,areaNum);
        return;
    }
    int type = map[cctv[depth].first][cctv[depth].second]-1; // cctv 종류
    int temp[9][9];
    memcpy(temp,map,sizeof(map));
    for(int i=0;i<rotateNum[type];i++){ // 회전
        int cnt =0;
        for(int j=0;j<arrow[type].size();j++){ // 화살표
            cnt += draw(depth,(arrow[type][j] + i)%4);
        }
        dfs(depth+1,areaNum - cnt);
        memcpy(map,temp,sizeof(temp));

    }
}

int main(){
    cin >> n >> m;
    int areaNum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] <= 5)cctv.push_back({i,j});
            else if(map[i][j] == 0)areaNum++;
        }
    }
    answer = areaNum;
    
    dfs(0,areaNum);
    cout << answer << '\n';
}
