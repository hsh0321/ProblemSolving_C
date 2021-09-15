//
//  BJ_2110_공유기설치.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/09/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[200001];
int N, C;

int main(void)
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    
    int start = 1, end = arr[N - 1] - arr[0];
    int res = 0;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int cnt = 1;
        int idx = 0;
        
        for (int i = 1; i < N; i++) {
            int dis = arr[i] - arr[idx];
            if (dis >= mid) {
                idx = i;
                cnt++;
            }
        }
        
        if (cnt >= C) {
            res = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    
    cout << res;
    return 0;
}
