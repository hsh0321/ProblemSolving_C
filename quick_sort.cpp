//
//  quick_sort.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/11/08.
//

#include <iostream>
#include <iostream>
using namespace std;

int partition(int* arr,int start,int end);

void quickSort(int* arr,int start,int end){
    int part2 = partition(arr, start, end); // 2번째 파티션의 시작인덱스
    if(start < part2 - 1){ // 배열의 크기가 1 이상
        quickSort(arr, start, part2 -1);
    }
    if(part2 < end){
        quickSort(arr, part2, end);
    }
}

int partition(int* arr, int start,int end){
    int pivot = arr[(start+end)/2];
    
    while(start <= end){
        while(arr[start] < pivot)start++;
        while(arr[end] > pivot)end--;
        if(start <= end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    
    return start;
}
 
int main(){
    int data[10] = {4, 1, 2, 3, 9, 7, 8, 6, 10, 5};
    
    quickSort(data, 0, 9);
    
    // 결과 확인
    for(int i=0; i<10; i++){
        printf("%d ", data[i]);
    }
    
    return 0;
}
