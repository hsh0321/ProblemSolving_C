//
//  BJ_11497_통나무건너뛰기.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/05/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        for(int i = 0; i < v.size()-2; i++){
            ans = max(ans,abs(v[i]-v[i+2]));
        }
        cout << ans << '\n';
    }
}
