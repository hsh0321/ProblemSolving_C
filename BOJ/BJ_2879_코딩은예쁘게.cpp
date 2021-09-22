//
//  BJ_2879_코딩은예쁘게.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/09/22.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, diff[1001], arr[1001];

int main(){
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    
    int temp;
    for (int i = 0; i < N; ++i){
        cin >> temp;
        diff[i] = temp - arr[i];
    }

    int maxh = diff[0], ret = 0;

    for (int i = 1; i < N; maxh = diff[i++]){
        if (maxh * diff[i] < 0) ret += abs(maxh);
        else if (abs(maxh) > abs(diff[i]))
            ret += abs(maxh - diff[i]);
    }
    
    cout << ret + abs(maxh);

    return 0;
}
