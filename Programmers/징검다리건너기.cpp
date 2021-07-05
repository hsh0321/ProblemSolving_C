#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(vector<int> stones,int k,int num){
    int cnt = 0;
    for(int i=0;i<stones.size();i++){
        if(stones[i] - num < 0)cnt++;
        else cnt = 0;
        
        if(cnt == k)return false;
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1, right = *max_element(stones.begin(),stones.end());
    while(right >= left){
        int mid = (left + right) / 2;
        if(check(stones,k,mid)){
            left = mid+1;
            answer = max(answer,mid);
        }else{
            right = mid-1;
        }
    }
    
    return answer;
}
