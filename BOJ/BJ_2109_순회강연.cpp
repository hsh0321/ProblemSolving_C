//
//  BJ_2109_순회강연.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/25.
//

#include <iostream>
#include <vector>lddldl
#include <algorithm>
#include <queue>
using namespace std;
 
int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;
int result;
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back({d, p});
    }
 
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        result += v[i].second;
 
        if (pq.size() > v[i].first) {
            result -= pq.top();
            pq.pop();
        }
    }
    
    cout << result;
 
    return 0;
}
