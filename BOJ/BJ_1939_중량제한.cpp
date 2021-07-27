//
//  BJ_1939_중량제한.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/27.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> adj[10001]; //pair:중량제한,연결된 정점

int Solve(int start, int dest)
{
    //각 지점으로 갈때 옮길 수 있는 중량의 최댓값을 저장(-1로 초기화)
    vector<int> result(n + 1, -1);

    priority_queue<pair<int, int>> pq;
    result[start] = 1000000001; //시작지점으로 옮길 수 있는 중량의 최댓값은 매우 큰수로 저장해 놓는다
    pq.push(make_pair(1000000001, start));

    while (!pq.empty())
    {
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();

        //이미 구한 here지점으로 옮길 수 있는 중량이 더 클때
        if (result[here] > here_cost)
            continue;

        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].second;
            int there_cost = min(adj[here][i].first, here_cost); //더 작은 값이 옮길 수 있는 중량이 된다

            //이미 구한 there지점으로 옮길 수 있는 중량제한 보다 더 클때
            if (result[there] < there_cost)
            {
                result[there] = there_cost;
                pq.push(make_pair(there_cost, there));
            }
        }
    }

    return result[dest];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    int f1, f2;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }

    cin >> f1 >> f2;

    cout << Solve(f1, f2);

    return 0;
}
