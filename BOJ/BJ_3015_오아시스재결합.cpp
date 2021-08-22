//
//  BJ_3015_오아시스재결합.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/08/22.
//

#include <iostream>
#include<stack>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    long long ans = 0;
    stack<pair<int,int>> st; // (높이, 연속횟수)
    for(int i=0;i<n;i++) {
        int h;
        cin >> h;
        pair<int,int> cur = { h, 1 };
        while (!st.empty()) {
            if (h >= st.top().first) {
                ans += st.top().second;
                if (h == st.top().first) { //연속횟수 갱신
                    cur.second += st.top().second;
                }
                st.pop();
            }
            else { //키가 작은 경우
                ans++;
                break;
            }
        }
        st.push(cur);
    }
    cout << ans << '\n';
}


