#include <iostream>
#include <string>

using namespace std;

string input_str, bomb, ans;
bool chk_fire;

int main()
{
    cin.sync_with_stdio(false);

    cin >> input_str >> bomb;

    int input_len = input_str.length();
    int bomb_len = bomb.length();

    for (int i = 0; i < input_len; i++)
    {
        ans += input_str[i];
        // 폭발문자열의 끝 문자와 일치할 경우 비교
        if (input_str[i] == bomb[bomb_len - 1] && i >= bomb_len - 1)
        {
            chk_fire = true;
            // ans에 들어간 최근 문자열을 bomb_len만큼 비교하여 폭발문자열과 일치하는지 비교한다.
            for (int j = 1; j < bomb_len; j++)
            {
                // 폭발문자열과 다른 문자가 있을 경우
                if (ans[ans.size() - 1 - j] != bomb[bomb_len - 1 - j])
                    chk_fire = false;
            }

            // 폭발문자열과 일치하면 폭발문자열의 길이만큼 ans의 끝을 pop() 시켜준다
            if (chk_fire)
            {
                for (int k = 0; k < bomb_len; k++)
                    ans.pop_back();
            }
        }
    }

    if (!ans.empty())
    {
        cout << ans;
    }
    else
        cout << "FRULA";

    return 0;
}