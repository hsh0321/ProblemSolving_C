//
//  BJ_2258_정육점.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/02.
//

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[100001];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].second >> p[i].first;
        p[i].second *= -1;
    }
    
    sort(p + 1, p + 1 + n);
    int s = 0, c = 0, mini = 2147483647, flag = 0;
    for (int i = 1; i <= n; i++) {
        s -= p[i].second;
        if (p[i].first == p[i - 1].first){
            c += p[i - 1].first;
        }else c = 0;
        if (s >= m){
            mini = min(mini, p[i].first + c), flag = 1;
        }
    }
    
    if(flag){
        cout << mini;
    }else{
        cout << -1;
    }

    return 0;
}
