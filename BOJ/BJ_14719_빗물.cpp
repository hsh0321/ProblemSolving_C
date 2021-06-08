//
//  BJ_14719_빗물.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/08.
//


#include <iostream>
#include <algorithm>
using namespace std;

int map[501];

int main() {
    int H, W;
    cin >> H >> W;

    int answer = 0;
    for (int i = 0; i < W;i++)cin >> map[i];

    
    for (int i = 0; i < W; i++) {
        int l, r;
        int lmax=0, rmax=0;
        for (l = i; l >= 0; l--) {
            lmax = max(lmax, map[l]);
        }
        for (r = i; r < W; r++) {
            rmax = max(rmax, map[r]);
        }
        if(lmax > map[i] && rmax > map[i])answer += min(rmax, lmax) - map[i];
    }
    cout << answer << '\n';

    return 0;
}
