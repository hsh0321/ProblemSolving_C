//
//  BJ_2468_안전영역.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/17.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[101][101];
bool visit[101][101];
int N;
int dr[4] = {1,-1,0,0}, dc[4]={0,0,1,-1};

int simulation(int w){
    int num_island = 0;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            visit[i][j] = false;
    
    
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j] || map[i][j] <= w)continue;
            num_island++;
            q.push({i,j});
            visit[i][j] = true;
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    pair<int,int> nxt = {cur.first + dr[d],cur.second + dc[d]};
                    if(nxt.first < 0 || nxt.first >= N || nxt.second < 0 || nxt.second >= N)continue;
                    if(map[nxt.first][nxt.second] <= w)continue;
                    if(visit[nxt.first][nxt.second])continue;
                    visit[nxt.first][nxt.second] = true;
                    q.push(nxt);
                }
            }
        }
    }
    
    return num_island;
}

int main(){
    int max_height = 0;
    
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            max_height = max(max_height,map[i][j]);
        }
    }
    
    int answer = 0;
    
    for(int w = 0; w<max_height;w++){
        answer = max(answer,simulation(w));
    }
    
    cout << answer;
    
    return 0;
}
