//
//  BJ_9465_스티커.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/10.
//

#include <iostream>
#include <algorithm>
using namespace std;

int map[2][100001];
int dp[2][100001];

int T,n;
int main(){
    cin >> T;
    
    while(T--){
        cin >> n;
        
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> map[i][j];
            }
        }
        
        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        for(int j=1;j<n;j++){
            dp[0][j] = max(dp[0][j-1],dp[1][j-1]+map[0][j]);
            dp[1][j] = max(dp[1][j-1],dp[0][j-1]+map[1][j]);
        }
        
        cout << max(dp[0][n-1],dp[1][n-1]) << endl;
    }
    
    
    
}
