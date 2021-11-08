//
//  merge_sort.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/11/04.
//


#include <iostream>
using namespace std;

void merge(int* arr,int* tmp,int start,int mid,int end){
    int idx = start;
    int part1 = start;
    int part2 = mid+1;
    
    for(int i=start;i<=end;i++)
        tmp[i] = arr[i];
    
    while(part1 <= mid && part2 <= end){
        if(tmp[part1] <= tmp[part2]){
            arr[idx] = tmp[part1];
            part1++;
        }else{
            arr[idx] = tmp[part2];
            part2++;
        }
        idx++;
    }
    
    for(int i=0;i<=mid-part1;i++){
        arr[idx + i] = tmp[part1 + i];
    }
}

void mergeSort(int* arr,int* tmp,int start,int end){
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(arr,tmp,start,mid);
        mergeSort(arr,tmp,mid+1,end);
        merge(arr,tmp,start,mid,end);
    }
}

void mergeSort(int* arr, int end){
    int tmp[8];
    mergeSort(arr,tmp,0,end);
}

int main(){
    int arr[8] = {1,4,5,2,8,7,3,6};
    
    mergeSort(arr,7);
    
    for(int i=0;i<8;i++)
        cout << arr[i] << " ";
    
    return 0;
}



