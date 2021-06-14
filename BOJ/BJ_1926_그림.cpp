//
//  BJ_1926_그림.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/11.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[501][501];
bool visit[501][501];
int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    
    int num_pic = 0;
    int max_size = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j] || map[i][j] == 0)continue;
            num_pic++; // 그림 추가
            queue<pair<int,int>> q;
            q.push({i,j});
            visit[i][j] = true;
            int tmp_size = 1;
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    pair<int,int> nxt = cur;
                    nxt.first += dr[d];
                    nxt.second += dc[d];
                    if(nxt.first < 0 || nxt.second < 0 || nxt.first >= n || nxt.second >= m)continue; // 범위 밖
                    if(!map[nxt.first][nxt.second])continue; // 그림이 아님
                    if(visit[nxt.first][nxt.second])continue; // 이미 방문
                    tmp_size++;
                    q.push(nxt);
                    visit[nxt.first][nxt.second] = true;
                }
            }
            max_size = max(max_size,tmp_size);
        }
    }
    cout << num_pic << '\n';
    cout << max_size << '\n';

    return 0;
}
