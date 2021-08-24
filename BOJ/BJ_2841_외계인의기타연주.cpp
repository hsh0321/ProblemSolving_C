//
//  BJ_2841_외계인의기타연주.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/08/01.
//

#include <iostream>
#include <stack>
using namespace std;

int N,P;

stack<int> line[7];

int main(){
    cin >> N >> P;
    
    int answer = 0;
    
    
    int l,p;
    for(int i=0;i<N;i++){
        bool flag = false;
        cin >> l >> p;
        if(!line[l].empty() && line[l].top() == p)continue;
        
        while(!line[l].empty() && line[l].top() > p){
            line[l].pop();
            answer++;
            flag = true;
        }
        if(flag && !line[l].empty() && line[l].top() == p){
            answer--;
            line[l].pop();
        }
        line[l].push(p);
        answer++;
    }
    
    cout << answer;
    return 0;
}
