#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string simulation(string p){
    // 1.
    if(p.size() == 0)return p;
    
    // 2.
    string u,v;
    int l=0,r=0;
    if(p[0] == '(')l++;
    else r++;
    for(int i=1;i<p.size();i++){
        if(p[i] == '(')l++;
        else r++;
        
        if(l == r){
            u = p.substr(0,i+1);
            v = p.substr(i+1,p.size()-1);
            break;
        }
    }
    
    cout << u << endl;
    cout << v << endl;
    
    // 3.
    stack<char> s;
    bool isCorrect = true;
    for(int i=0;i<u.size();i++){
        if(u[i] == '('){
            s.push(u[i]);
        }else if(u[i] == ')'){
            if(s.empty() || s.top() != '('){
                isCorrect = false;
                break;
            }
            s.pop();
        }
    }
    
    if(isCorrect){ // 3-1
        u += simulation(v);
    }else{ // 4
        string tmp = "(";
        tmp += simulation(v);
        tmp += ')';
        for(int i=1;i<u.size()-1;i++){
            if(u[i] == '(') tmp += ')';
            else tmp += '(';
        }
        return tmp;
    }
    return u;
}

string solution(string p) {
    string answer = "";
    
    answer = simulation(p);
    
    return answer;
}
