#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;
        string elem;
        unordered_map<string, int> map;
        vector<string> v;
        bool answer = true;
        for (int i = 0; i < n; i++) {
            cin >> elem;
            string tmp;
            v.push_back(elem);
            map[elem]++;
        }

        for (int i = 0; i < v.size(); i++) {
            for (int j = 1; j < v[i].size(); j++) {
                string tmp = v[i].substr(0, j);
                if (map[tmp] > 0)answer = false;
            }
            if (map[v[i]] > 1)answer = false;
        }

        if (answer)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}