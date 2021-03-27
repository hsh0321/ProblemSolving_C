//
//  BJ_11660_구간합구하기.cpp
//  asddas
//
//  Created by 황성현 on 2021/03/27.
//

#include <iostream>

using namespace std;

int dp[1025][1025];
int map[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    
    
    // dp[x][y] = 0,0에서 x,y까지의 합
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) + map[i][j] - dp[i-1][j-1];
        }
    }
    
    // x1,y1에서 x2,y2까지의 합
    // dp[x2][y2] - (dp[x1-1][y2] + dp[x2][y1-1])+ dp[x1-1][y1-1]
    while(m--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - (dp[x1-1][y2] + dp[x2][y1-1])+ dp[x1-1][y1-1] << '\n';
    }
}
