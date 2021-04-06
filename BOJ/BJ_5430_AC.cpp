//
//  BJ_5430_AC.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/04/06.
//

#include <iostream>
#include <sstream>
#include <deque>
using namespace std;

int main(){
    int T=0;
    cin >> T;
    while(T--){
        string p,tmp;
        deque<string> dq;
       
        cin >> p;
        
        int size;
        cin >> size;
        cin >> tmp;
        tmp = tmp.substr(1,tmp.length()-2);

        stringstream ss(tmp);
        string buf;
        while(getline(ss,buf,',')){
            dq.push_back(buf);
        }
        
        bool flag = false; // error
        bool dir = true; // true 정방향 false 반전
        for(int j=0;j<p.size();j++){
            if(p[j] == 'R'){
                dir = !dir;
            }else if(p[j] == 'D'){
                if(dq.empty()){ // 데크가 비었을 때
                    flag = true;
                    cout << "error" << endl;
                    break;
                }
                if(dir){
                    dq.pop_front();
                }else{
                    dq.pop_back();
                }
            }
        }
        
        if(!flag){
            if(dq.size() ==0){ // 비어있을 때
                cout << "[]" << endl;
                continue;
            }
            string ans;
            ans += '[';
            while(!dq.empty()){
                if(dir){
                    ans += dq.front() + ',';
                    dq.pop_front();
                }else{
                    ans += dq.back() + ',';
                    dq.pop_back();
                }
            }
            ans.pop_back();
            ans += ']';
            cout << ans << endl;
        }
    }
}
