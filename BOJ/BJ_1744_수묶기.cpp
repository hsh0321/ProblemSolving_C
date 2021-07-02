//
//  BJ_1744_수묶기.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/03.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[10001];
int N;

int main(){
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N); // 오름차순 정렬
    
    vector<int> pos;
    queue<int> neg;
    bool haveZero = false;
    int answer = 0;
    for(int i=0;i<N;i++){
        if(arr[i] < 0){
            neg.push(arr[i]);
        }else if(arr[i] == 0){
            haveZero = true;
        }else if(arr[i] == 1){
            answer += arr[i];
        }else{
            pos.push_back(arr[i]);
        }
    }
    
    int a,b;
    while(pos.size() > 1){
        a = pos.back();
        pos.pop_back();
        b = pos.back();
        pos.pop_back();
        answer += a*b;
    }
    if(!pos.empty())answer += pos.back();

    while(neg.size() > 1){
        a = neg.front();
        neg.pop();
        b = neg.front();
        neg.pop();
        answer += a*b;
    }
    
    if(!neg.empty()){
        if(!haveZero){
            answer += neg.back();
        }
    }
    
    cout << answer << endl;
    
    
    return 0;
}
