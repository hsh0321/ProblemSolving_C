//
//  BJ_15591_MooTube.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/03.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class info {
public:
    int idx, val;
};


info tmp;
vector<info> map[5001];
bool visit[5001];
int N, Q;

int main() {
   cin >> N >> Q;
    
    int p,q,r;
    for (int i = 0; i < N-1; i++) {
        cin >> p >> q >> r;
        tmp.idx = q;
        tmp.val = r;
        map[p].push_back(tmp);
        tmp.idx = p;
        map[q].push_back(tmp);
    }
    
    int k,v;
    for (int i = 0; i < Q; i++) {
        cin >> k >> v;
        
        int result = 0;
       
        for (int j = 1; j <= N; j++)
            visit[j] = false;

        visit[v] = true;
        queue<int> q;
        q.push(v);
        while (!q.empty()) {
            int cidx = q.front();
            q.pop();
            for (int j = 0; j < map[cidx].size(); j++) {
                int next = map[cidx][j].idx;
                if (visit[next]) continue;
                int nv = map[cidx][j].val;
                if (nv >= k) {
                    visit[next] = true;
                    result++;
                    q.push(next);
                }
            }
        }
        cout << result << '\n';
    }
    return 0;
}
