//Prim

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Line {
public:
    int weight;
    int dst;
};

class cmp {
public:
    bool operator()(Line n1, Line n2) {
        return n1.weight > n2.weight;
    }
};

int n, m;
vector<Line> com[1001];
bool visited[1001] = { false, };
priority_queue<Line, vector<Line>, cmp> pq;
int cost = 0;

void prim(int init) {
    visited[init] = true;
    for (Line pa : com[init]) {
        pq.push(pa);
    }
    while (!pq.empty()) {
        Line cur = pq.top();
        pq.pop();
        if (visited[cur.dst]) continue;
        visited[cur.dst] = true;
        cost += cur.weight;
        for (Line pa : com[cur.dst]) {
            if (!visited[pa.dst]) {
                pq.push(pa);
            }
        }
    }
    cout << cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v, weight;
        cin >> u >> v >> weight;
        com[u].push_back({ weight, v });
        com[v].push_back({ weight, u });
    }
    prim(1);
    return 0;
}