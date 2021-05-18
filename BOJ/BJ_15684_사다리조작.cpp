//
//  BJ_15684_사다리조작.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/05/01.
//

#include <iostream>

using namespace std;

int N, M, H;
bool ladder[31][11];
int cnt;
int ladderNum;

bool flag;

bool check() {
    for (int i = 1; i <= N; i++) {
        int nxt = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][nxt])nxt++;
            else if (ladder[j][nxt - 1])nxt--;
        }
        if (nxt != i)return false;
    }
    return true;
}


void dfs(int y, int cnt) {
    if (flag == true)return;
    if (cnt == ladderNum) {
        flag = check();
        return;
    }
    for (int i = y; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (ladder[i][j] == 0 && ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0){
                ladder[i][j] = true;
                dfs(i, cnt + 1);
                ladder[i][j] = false;
            }
        }
    }
    return;
}




int main() {
    int a = 0, b = 0;
    
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ladder[a][b] = true;
    }
    
    for (int i = 0; i <= 3; i++) {
        flag = false;
        ladderNum = i;
        dfs(1, 0);
        
        if (flag == true) {
            cout << i << "\n";
            return 0;
        }
    }
    
    cout << -1 << "\n";
    return 0;
    
}
