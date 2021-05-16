#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int map[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 테이블 입력
    int cnt = 1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            map[i][j] = cnt++;
        }
    }
    
    // 회전
    for(int i=0;i<queries.size();i++){
        int r1,c1,r2,c2,min_num;
        r1 = queries[i][0]-1,c1 = queries[i][1]-1;
        r2 = queries[i][2]-1,c2 = queries[i][3]-1;
    
        min_num = cnt; // 최대값
        
        int tmp = map[r1][c1];
        min_num = min(min_num,map[r1][c1]);
        for(int j=r1+1;j<=r2;j++){ // 좌
            map[j-1][c1] = map[j][c1];
            min_num = min(min_num,map[j][c1]);
        }
        for(int j=c1+1;j<=c2;j++){ // 하
            map[r2][j-1] = map[r2][j];
            min_num = min(min_num,map[r2][j]);
        }
        for(int j=r2-1;j>=r1;j--){ // 우
            map[j+1][c2] = map[j][c2];
            min_num = min(min_num,map[j][c2]);
        }
        for(int j=c2-1;j>=c1+1;j--){ // 상
            map[r1][j+1] = map[r1][j];
            min_num = min(min_num,map[r1][j]);
        }
        map[r1][c1+1] = tmp;
        
        // for(int r=0;r<rows;r++){
        //     for(int c=0;c<columns;c++){
        //         cout << map[r][c] << " ";
        //     }
        //     cout << endl;
        // }
        
        answer.push_back(min_num);
    }
    
    return answer;
}
