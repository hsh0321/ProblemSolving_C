//
//  BJ_14891_톱니바퀴.cpp
//  Algorithm
//
//  Created by 황성현 on 2021/03/16.
//

#include <iostream>
#include <string>
using namespace std;

string wheels[4]; // N 0 S 1
bool check[4];

void dfs(int num,int dir){
    // 2:3시 6:9시
    check[num] = true;
    if(num > 0 && !check[num-1] && wheels[num][6] != wheels[num-1][2]){ // 좌측
        dfs(num-1,dir*-1);
    }
    if(num < 3 && !check[num+1] && wheels[num][2] != wheels[num+1][6]){ // 우측
        dfs(num+1,dir*-1);
    }
    if(dir == 1){ // 시계방향 회전
        wheels[num] = wheels[num][7] + wheels[num].substr(0,7);
    }else{
        wheels[num] = wheels[num].substr(1,7) + wheels[num][0];
    }
}

int main(){
    for(int i=0;i<4;i++)
        cin >> wheels[i];
    
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        int num, dir;
        cin >> num >> dir;
        dfs(num-1,dir);
        for (int j=0; j<4; j++)
            check[j] = false;
    }
    int answer=0;
    for(int i=0;i<4;i++){
        if(wheels[i][0] == '1'){
            if(i==0){
                answer += 1;
            }else if(i==1){
                answer += 2;
            }else if(i==2){
                answer += 4;
            }else{
                answer += 8;
            }
        }
    }
    cout << answer << endl;
    
    return 0;
}


