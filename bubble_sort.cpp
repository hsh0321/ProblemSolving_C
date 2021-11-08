//
//  bubble_sort.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/11/08.
//

// stable sort
// O(N^2)

#include <iostream>

using namespace std;

void bubbleSort(int n,int* arr){
    for(int i=0;i<8;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){
    int arr[8] = {1,3,2,5,7,4,8,6};
    
    bubbleSort(8,arr);
    
    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }
}
