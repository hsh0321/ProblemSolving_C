//
//  selection_sort.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/11/08.
//

// unstable sort
// O(N^2)

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

void selection_sort(int n,int* arr){
    for(int i=0;i<n;i++){
        int tmp = arr[i]; // 최소값 저장
        int idx = 0; // 최소값 인덱스
        for(int j=i;j<n;j++){
            if(tmp >= arr[j]){
                tmp = arr[j];
                idx = j;
            }
        }
        swap(arr[i],arr[idx]);
    }
}

int main(){
    int arr[8] = {3,2,1,4,7,8,6,5};
    
    selection_sort(8,arr);
    
    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
