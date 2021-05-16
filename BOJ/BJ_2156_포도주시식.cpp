//
//  main.cpp
//  asddas
//
//  Created by 황성현 on 2021/03/27.
//


#include <iostream>
#include <algorithm>
using namespace std;

int podo[10001];
int dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> podo[i];
    }
    
    // 연속 세잔 못 마심.
    // dp[i] = i번째 까지 최대로 마실 수 있는 포도주
    // 1. 전날
    // 2. 3일전+어제+오늘
    // 3. 2일전+오늘
    
    dp[0] = 0;
    dp[1] = podo[1];
    dp[2] = podo[1] + podo[2];
    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-1],max(dp[i-3]+podo[i-1] +podo[i],dp[i-2]+podo[i]));
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}
