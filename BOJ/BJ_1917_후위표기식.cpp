#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string s;
    stack<char> stack;
    cin >> s;

    string ans = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            ans += s[i];
        }else{
            if (s[i] == '(')
                stack.push(s[i]);
            else if (s[i] == '*' || s[i] == '/'){
                while (!stack.empty() && (stack.top() == '*' || stack.top() == '/')){
                    ans += stack.top();
                    stack.pop();
                }
                stack.push(s[i]);
            }else if (s[i] == '+' || s[i] == '-'){
                while (!stack.empty() && stack.top() != '('){
                    ans += stack.top();
                    stack.pop();
                }
                stack.push(s[i]);
            }else if (s[i] == ')'){
                while (!stack.empty() && stack.top() != '('){
                    ans += stack.top();
                    stack.pop();
                }
                stack.pop();
            }
        }
    }
    while (!stack.empty()){
        ans += stack.top();
        stack.pop();
    }

    cout << ans;
    
    return 0;
}
