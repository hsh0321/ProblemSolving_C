#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
int visit[101][101];

int solution(vector<vector<int> > maps){
    int answer = 0;
    
    queue<pair<int,int>> q;
    
    int n = maps.size();
    int m = maps[0].size();
    
    q.push({0,0});
    visit[0][0] = 1;
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)continue;
            if(maps[nr][nc] == 0)continue;
            if(visit[nr][nc] != 0)continue;
            visit[nr][nc] = visit[r][c] + 1;
            q.push({nr,nc});
        }   
    }
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    if(visit[n-1][m-1] == 0)return -1;
    else return visit[n-1][m-1];
}
