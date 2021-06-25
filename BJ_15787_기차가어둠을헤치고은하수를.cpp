//
//  BJ_15787_기차가어둠을헤치고은하수를.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/25.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N,M;

long long train[100001];
unordered_map<long long, bool> check;

int main(){
    cin >> N >> M;
    
    int op,t,n;
    for(int i=0;i<M;i++){
        cin >> op >> t;
        long long tmp;
        if(op == 1){
            cin >> n;
            tmp = 1;
            tmp = tmp << (n-1);
            train[t] = (train[t]|tmp);
        }else if(op ==2){
            cin >> n;
            tmp = 1;
            tmp = tmp << (n-1);
            if((train[t] & tmp) > 0)train[t] = (train[t]-tmp);
        
        }else if(op==3){
            train[t] = train[t] << 1;
            int left = 1 << 20;
            if((train[t]&left) > 0){
                train[t] -= left;
            }
        }else{
            train[t] = train[t] >> 1;
        }
    }
    
    int answer = 0;
    for(int i=1;i<=N;i++){
        if(!check[train[i]]){ // 기록되지 않음
            check[train[i]] = true;
            answer++;
        }
    }
    
    cout << answer;
    
    return 0;
}


