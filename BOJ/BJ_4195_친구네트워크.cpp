//Union-find
#include <iostream>
#include <map>
using namespace std;

int parent[2000001],num[2000001];

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a != b) {
        parent[b] = a;
        num[a] += num[b];
        num[b] = 1;
    }
    return num[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int F;
        cin >> F;

        for (int j = 1; j <= 2 * F; j++) {
            parent[j] = j;
            num[j] = 1;
        }

        map<string, int> index;
        string s1, s2;
        int idx1, idx2;
        int num = 1;
        for (int j = 0; j < F; j++) {
            cin >> s1 >> s2;
            if (index.count(s1) == 0) index[s1] = num++;
            idx1 = index[s1];
            if (index.count(s2) == 0) index[s2] = num++;
            idx2 = index[s2];
            cout << unionParent(idx1, idx2) << '\n';
        }
    }
    return 0;
}