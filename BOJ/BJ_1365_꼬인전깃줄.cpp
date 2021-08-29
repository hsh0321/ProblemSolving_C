//
//  BJ_1365_꼬인전깃줄.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/08/27.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> line;

int main(){
    cin >> N;
    
    int len;
    line.push_back(0);
    for(int i=0;i<N;i++){
        cin >> len;
        if(line.back() < len){
            line.push_back(len);
        }else{
            auto it = lower_bound(line.begin(),line.end(),len);
            *it = len;
            cout << *it << '\n';
        }
    }
    
    cout << N-(line.size()-1) << '\n';
    
    
    return 0;
}
