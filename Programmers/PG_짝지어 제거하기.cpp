#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> st;
    
    for(int i=0;i<s.size();i++){
        if(!st.empty()){
            if(st.top() == s[i]){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }
    
    if(st.empty())return 1;
    else return 0;
}
