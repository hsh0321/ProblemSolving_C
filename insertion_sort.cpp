//
//  insertion_sort.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/11/08.
//

// stable sort
// O(N^2)

#include <iostream>

using namespace std;

void insertion_sort(int n,int* arr){
    int j;
    for(int i=0;i<n-1;i++){
        j = i;
        while(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
            j--;
        }
    }
}


int main(){
    int arr[8] = {1,5,3,7,2,6,8,4};
    
    insertion_sort(8,arr);
    
    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
