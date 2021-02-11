#include <iostream>
#include <queue>
#include <algorithm>
#define INF 99999999

using namespace std;

class node {
public:
	int n, weight;
	bool operator()(node n1, node n2) {
		return n1.weight > n2.weight;
	}
};


int V, E, K;
int u, v, w;
vector<node> graph[20001];
int dist[20001];


void dijkstra() {
	priority_queue<node, vector<node>, node> pq;
	pq.push({ K,0 });
	while (!pq.empty()) {
		int n1 = pq.top().n, w1 = pq.top().weight;
		pq.pop();
		if (dist[n1] != INF)continue;
		dist[n1] = w1;
		for (int i = 0; i < graph[n1].size(); i++) {
			if (dist[graph[n1][i].n] != INF)continue;
			pq.push({ graph[n1][i].n,w1 + graph[n1][i].weight });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V >> E >> K; // 정점 간선 출발노드
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

}