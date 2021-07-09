//
//  BJ_18428_감시피하기.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/08.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
char map[7][7];
vector<pair<int,int>> teachers;

int dr[4] = {1,-1,0,0},dc[4] = {0,0,1,-1};

bool check = false;

bool simulation(){
    for(int i=0;i<teachers.size();i++){ // 선생
        int r = teachers[i].first;
        int c = teachers[i].second;
        for(int d=0;d<4;d++){ // 방향
            for(int m=1;m<=N;m++){ // 거리
                int nr = r + dr[d]*m;
                int nc = c + dc[d]*m;
                if(nr < 0 || nr >= N || nc < 0 || nc >=N)break;
                if(map[nr][nc] == 'S')return false; // 학생이면
                if(map[nr][nc] == 'O')break; // 장애물이라면
            }
        }
    }
    return true;
}

void dfs(int num,int loc){ // 장애물의 수, 현재 위치
    if(num == 3){ // 장애물 3개 설치
        if(simulation())check = true;
//        cout << endl;
//        for(int i=0;i<N;i++){
//            for(int j=0;j<N;j++){
//                cout << map[i][j] << " ";
//            }
//            cout << endl;
//        }
        return;
    }
    
    for(int i=loc;i<N*N;i++){
        int nr = i/N;
        int nc = i%N;
        if(map[nr][nc] == 'X'){ // 장애물 설치 가능
            map[nr][nc] = 'O';
            dfs(num+1,i);
            map[nr][nc] = 'X';
        }
    }
}

int main(){
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 'T')teachers.push_back({i,j});
        }
    }
    
    dfs(0,0);
    
    if(check)cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
