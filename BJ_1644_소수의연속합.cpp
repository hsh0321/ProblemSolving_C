//
//  BJ_1644_소수의연속합.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n+1, true);

    for (int i = 2; i*i <= n; i++) {
        if (!v[i]) continue;
        for (int j = i+i; j <= n; j+=i) {
            v[j] = false;
        }
    }
    vector<int> prime;

    for (int i = 2; i <= n; i++) {
        if(v[i]) prime.push_back(i);
    }
    int left = 0, right = 0;
    int sum = 0;
    int ans = 0;
    while (true) {
        if (sum > n) {
            sum -= prime[left];
            left++;
        }
        else if(sum<n){
            if (right >= prime.size()) break;
            sum += prime[right];
            right++;
        }
        else {
            ans++;
            if (right >= prime.size()) break;
            sum += prime[right];
            right++;
        }
    }
    cout << ans;

    return 0;
}
