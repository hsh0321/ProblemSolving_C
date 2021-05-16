//
//  BJ_1715_카드정렬하기.cpp
//  Algorithm
//
//  Created by 황성현 on 2021/03/16.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    int tmp;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<N;i++){
        cin >> tmp;
        pq.push(tmp);
    }

    
    int answer=0;
    while(pq.size() != 1){
        int t = 0;
        answer += pq.top();
        t+= pq.top();
        pq.pop();
        answer += pq.top();
        pq.pop();
        pq.push(answer);
    }
    cout << answer;
}

// 10 20 30 40
// 10+20 30+30 60+40
// 30 60 100
