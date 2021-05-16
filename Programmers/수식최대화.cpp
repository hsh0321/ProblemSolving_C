#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calculate(long long a, long long b, char opr) {
    if (opr == '+')
        return a + b;
    else if (opr == '-')
        return a - b;
    else if (opr == '*')
        return a * b;
    
    return -1;
}

long long solution(string expression) {
    long long answer = 0;
    vector<char>operator_list = { '*', '+', '-' };
    vector <long long> nums;
    vector <char> op;
    string num = "";
    
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            nums.push_back(atoi(num.c_str()));
            num = "";
            op.push_back(expression[i]);
        }
        else {
            num += expression[i];
        }
    }
    
    nums.push_back(atoi(num.c_str()));
    do {
        vector <long long>  temp_nums = nums;
        vector <char> tmp_op = op;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < tmp_op.size(); j++) {
                if (tmp_op[j] == operator_list[i]) {
                    temp_nums[j] = calculate(temp_nums[j], temp_nums[j + 1], operator_list[i]);
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    tmp_op.erase(tmp_op.begin() + j);
                    j--;
                }
            }
        }
        if (abs(temp_nums.front()) > answer)
            answer = abs(temp_nums.front());
    } while (next_permutation(operator_list.begin(),operator_list.end()));
    return answer;
}
