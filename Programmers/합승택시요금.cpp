#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int map[201][201];
int INF = 10000001;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j] = INF;
            if(i==j)map[i][j] = 0;
        }
    }
    
    for(int i=0;i<fares.size();i++){
        map[fares[i][0]][fares[i][1]] = fares[i][2];
        map[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                map[j][k] = min(map[j][i] + map[i][k],map[j][k]);
            }
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for(int i=1;i<=n;i++){
        answer = min(answer,map[s][i] + map[i][a] + map[i][b]);
    }
    
    return answer;
}
