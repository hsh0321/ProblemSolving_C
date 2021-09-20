//
//  BJ_1937_욕심쟁이판다.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/09/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[501][501];
int dp[501][501];
int answer = 0;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int dfs(int r, int c){
    if (dp[r][c] != 0)return dp[r][c];

    dp[r][c] = 1; // 처음으로 1 지정!

    for (int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < n && nr >=0 && nc <n && nc >= 0){
            //새 좌표가 대나무가 더 많아야 이동 가능
            if (map[nr][nc] > map[r][c]){
                dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
            }
        }
    }
    return dp[r][c];
}



int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            answer = max(answer,dfs(i, j));
        }
    }

    cout << answer<<endl;
    return 0;

}
