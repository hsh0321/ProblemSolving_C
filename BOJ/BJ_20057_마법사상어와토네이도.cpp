//
//  BJ_20057_마법사상어와토네이도.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/09/16.
//

#include <iostream>
#include <math.h>
using namespace std;

int N; // 토네이도 크기
int map[1010][1010];
int dir[1010][1010]; // 토네이도 방향

int tr[4] = {0,1,0,-1}, tc[4] = {1,0,-1,0}; // 토네이도 초기화

// 1 좌 2 상 3 우 4 하
int dr[4] = {0,-1,0,1}, dc[4] = {-1,0,1,0};

// 방향에 따른 모래 비율
int sr[4][10] = {{-2,-1,-1,-1,0,1,1,1,2,0},
                {0,-1,0,1,-2,-1,0,1,0,-1},
                {2,1,1,1,0,-1,-1,-1,-2,0},
                {0,1,0,-1,2,1,0,-1,0,1}};

int sc[4][10] = {{0,-1,0,1,-2,-1,0,1,0,-1},
                {2,1,1,1,0,-1,-1,-1,-2,0},
                {0,1,0,-1,2,1,0,-1,0,1},
                {-2,-1,-1,-1,0,1,1,1,2,0}};

double per[9] = {0.02,0.1,0.07,0.01,0.05,0.1,0.07,0.01,0.02};


void init_tornado(){
    int r = 0, c = 0;
    int d = 0; // 초기 방향
    
    dir[0][0] = 1;
    while(!(r == N/2 && c == N/2)){ // 중앙까지
        r += tr[d]; c += tc[d];
        if(r < 0 || c < 0 || r >= N || c >= N
           || dir[r][c] != 0){ // 방향 전환
            r -= tr[d]; c -= tc[d];
            d++;
            d %= 4;
            continue;
        }
        dir[r][c] = d+1;
    }
    
    dir[N/2][N/2] = 1;
}

void simulation(){
    int r = N/2 + 2, c = N/2 + 2;
    
    int d;
    int sand; // 모래의 총량
    
    
    while(!(r==2 && c==2)){
        d = dir[r-2][c-2] - 1;
        r += dr[d]; c += dc[d];
        sand = map[r][c];
        map[r][c] = 0;
        if(sand == 0)continue; // 모래가 없을 때
        int sum = 0; // 차감된 양
        for(int i=0;i<9;i++){
            int nr = r + sr[d][i];
            int nc = c + sc[d][i];
            map[nr][nc] += floor(sand*per[i]);
            sum += floor(sand*per[i]);
        }
        map[r+sr[d][9]][c+sc[d][9]] += sand - sum;
    }
}

int main(){
    cin >> N;
  
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i+2][j+2]; // padding
        }
    }
    

    init_tornado();
    
    simulation();
    
    // 범위 밖 모래 계산
    int ans = 0;
    for(int i=0;i<N+4;i++){
        for(int j=0;j<N+4;j++){
            if(i >= 2 && i < N+2 && j >= 2 && j < N+2)continue;
            ans += map[i][j];
        }
    }
    cout << ans;

    return 0;
}
