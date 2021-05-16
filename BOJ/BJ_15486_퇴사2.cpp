//
//  BJ_15486_퇴사2.cpp
//  asddas
//
//  Created by 황성현 on 2021/03/27.
//

#include <iostream>
#include <algorithm>
using namespace std;

int t[1500051];
int p[1500051];

int dp[1500051];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> t[i] >> p[i];
    }
    
    // dp[i] = i일 전까지 받을 수 있는 돈
    // dp[i+t[i]] 를 기준으로 비교
    int m=0;
    for(int i=1;i<=N+1;i++){
        m = max(m,dp[i]);
        if(i+t[i] > N + 1)continue;
        dp[i+t[i]] = max(m+p[i],dp[i+t[i]]);
        // t[i] 일 후 받는 날의 최대값
    }
    cout << m << '\n';
}
