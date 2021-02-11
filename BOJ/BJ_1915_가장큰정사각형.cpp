#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
int map[1002][1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= s.length(); j++) {
            if (s[j - 1] == '1') {
                map[i][j] = 1;
            }  
            else {
                map[i][j] = 0;
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] != 0)
            {
                map[i][j] = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) + 1;
                if (max < map[i][j]) max = map[i][j];
            }
        }
    }

    cout << max * max;

    return 0;
}
