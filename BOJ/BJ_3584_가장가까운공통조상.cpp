//
//  BJ_3584_가장가까운공통조상.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/30.
//

#include<iostream>
#include<vector>

using namespace std;

int T, N;
vector<vector<int>> V;
vector<int> parent;
vector<int> depth;

void dfs(int here, int dep) {
    depth[here] = dep;
    for (int i = 0; i < V[here].size(); i++) {
        int there = V[here][i];
        dfs(there, dep + 1);
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        
        V.assign(N + 1, vector<int>());
        parent.assign(N + 1, 0);
        depth.assign(N + 1, 0);

        int u, v;
        for (int i = 0; i < N - 1; i++) {
            cin >> u >> v;
            V[u].push_back(v);
            parent[v] = u;
        }


        for (int i = 1; i <= N; i++) {
            if (!parent[i]) {  // 루트 노드
                parent[i] = i;
                dfs(i, 1);
                break;
            }
        }

        cin >> u >> v;
        while (depth[u] != depth[v]) {
            if (depth[u] < depth[v]) {
                v = parent[v];
            }
            else {
                u = parent[u];
            }
        }
        while (u != v) {
            v = parent[v];
            u = parent[u];
        }

        cout << v << endl;

    }
}
