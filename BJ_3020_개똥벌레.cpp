//
//  BJ_3020_개똥벌레.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/08/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int down[500001]; // 석순 down[1] = 개똥벌레가 1의 높이로 날 때 부수는 석순의 개수
int up[500001]; // 종유석
vector<int> v;

int main() {

    int N, H, val;
    cin >> N >> H;
    
    for (int i = 0; i < N; i++) {
        cin >> val;
        if (i % 2 == 0) down[val]++;
        else up[val]++;
    }
    
    for (int i = H-1; i >= 1; i--) {
        down[i] += down[i + 1];
        up[i] += up[i + 1];
    }
    
    //밑에서부터 높이 i일때 부수는 장애물 수
    for (int i = 1; i <= H; i++){
        v.push_back(down[i] + up[H - i + 1]);
    }
    
    sort(v.begin(),v.end());
    
    int num = 1;
    int result = v[0];
    
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == result) num++;
        else break;
    }
    
    cout << result << " " << num;
    
    return 0;
}
