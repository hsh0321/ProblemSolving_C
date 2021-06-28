//
//  BJ_1261_알고스팟.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/27.
//

#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int visit[101][101];

int dr[4] = {1,-1,0,0},dc[4]={0,0,1,-1};

int main(){
    int N,M;
    cin >> M >> N;
    
    string s;
    for(int i=0;i<N;i++){
        cin >> s;
        for(int j=0;j<s.size();j++){
            map[i][j] = s[j] - '0';
        }
    }
    
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0] = 1;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pair<int,int> nxt = {cur.first + dr[i],cur.second + dc[i]};
            if(nxt.first < 0 || nxt.second <0 || nxt.first >= N || nxt.second >= M)continue;
            if(visit[nxt.first][nxt.second] != 0 && visit[nxt.first][nxt.second] <= visit[cur.first][cur.second])continue;
            if(map[nxt.first][nxt.second] == 1){ // 벽
                if(visit[nxt.first][nxt.second] != 0 && visit[nxt.first][nxt.second] <= visit[cur.first][cur.second] + 1)continue;
                visit[nxt.first][nxt.second] = visit[cur.first][cur.second] + 1;
            }else{ // 벽이 아닐때
                visit[nxt.first][nxt.second] = visit[cur.first][cur.second];
            }
            q.push(nxt);
        }
    }
    
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            cout << visit[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << visit[N-1][M-1]-1 << '\n';
    
}
