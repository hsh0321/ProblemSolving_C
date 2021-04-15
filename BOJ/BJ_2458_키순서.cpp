//
//  BJ_2458_키순서.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/04/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int map[501][501];
int INF = 10000000;

int main(){
    cin >> N >> M;
    int a,b;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            map[i][j] = INF;
    
    for(int i=0;i<M;i++){
        cin >> a >> b;
        map[a-1][b-1] = 1;
    }
    
    // k = 거쳐가는 노드
    for(int k = 0; k < N; k++) {
        // i = 출발 노드
        for(int i = 0; i < N; i++) {
            // j = 도착 노드
            for(int j = 0; j < N; j++) {
                if(map[i][k] + map[k][j] < map[i][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            if(map[i][j] > 1000)cout << 0 << ' ';
//            else cout << map[i][j] << ' ';
//        }
//        cout << endl;
//    }
    
    int answer = 0;
    for(int i=0;i<N;i++){
        bool chk = false;
        for(int j=0;j<N;j++){
            if(i==j)continue;
            if(min(map[i][j],map[j][i]) >= INF){
                chk = true;
                break;
            }
        }
        if(!chk)answer++;
    }
    cout << answer << endl;
}
