#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string tmp = s;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        // cout << tmp << " ";
        stack<char> stack;
        
        bool flag = false;
        for(int j=0;j<tmp.size();j++){
            switch(tmp[j]){
                case '(':
                    stack.push(')');
                    break;
                case '[':
                    stack.push(']');
                    break;
                case '{':
                    stack.push('}');
                    break;
                case ')':
                    if(stack.empty())flag=true;
                    if(stack.top() == tmp[j]){
                        stack.pop();
                    }else{
                        flag = true;
                    }
                    break;
                case ']':
                    if(stack.empty())flag=true;
                    
                    if(stack.top() == tmp[j]){
                        stack.pop();
                    }else{
                        flag = true;
                    }
                    break;
                case '}':
                    if(stack.empty())flag=true;
                    
                    if(stack.top() == tmp[j]){
                        stack.pop();
                    }else{
                        flag = true;
                    }
                    break;
            }
            if(flag)break;
        }
        if(stack.empty() && !flag){
            answer++; 
            // cout << "OK";
        }
        // cout << endl;
        tmp = tmp.substr(1,tmp.size()) + tmp[0];
    }

    return answer;
}
