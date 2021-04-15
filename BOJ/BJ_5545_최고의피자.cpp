//
//  BJ_5545_최고의피자.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/04/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,A,B;
    cin >> N;
    cin >> A >> B;
    int calories = 0;
    cin >> calories;
    
    vector<int> v;
    int tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end(),greater<int>());
    
    int ans = calories / A;
    for(int i=0;i<v.size();i++){
        calories += v[i];
        ans = max(ans,calories/(A+(B*(i+1))));
    }
    
    cout << ans;
    
    return 0;
}
