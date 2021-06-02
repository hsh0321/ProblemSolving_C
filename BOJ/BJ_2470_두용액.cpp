//
//  BJ_2470_두용액.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/01.
//

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(){
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N);
    
    int l=0, r=N-1;
    
    int sum;
    int left = arr[l], right = arr[r];
    int min_sum = left + right;
    while(l-r){
        sum = arr[l] + arr[r];
        if(abs(min_sum) > abs(sum)){
            min_sum = sum;
            left = arr[l];
            right = arr[r];
        }
        
        if(sum<=0)l++;
        else r--;
    }
    
    cout << left << " " << right;
}
