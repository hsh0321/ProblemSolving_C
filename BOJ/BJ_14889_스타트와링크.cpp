#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[21][21];
int check[21];

int permutation(int n, int r) {
    int answer = 99999999;
    if (r > n) return 0;
    vector<int> mask;

    for (int i = 0; i < n; i++) {
        if (i < r) {
            mask.push_back(0);
        }
        else mask.push_back(1);
    }

    sort(mask.begin(), mask.end());

    while (1) {
        vector<int> start, link;

        for (int i = 0; i < n; i++) {
            if (mask[i] == 0) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        int a = 0, b = 0;

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                a += map[start[i]][start[j]];
                //a += map[start[j]][start[i]];
                b += map[link[i]][link[j]];
                //b += map[link[j]][link[i]];
            }
        }


        answer = min(answer, abs(a - b));

        if (!next_permutation(mask.begin(), mask.end())) break;
    }

    return answer;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cout << permutation(n, n / 2);

    return 0;
}