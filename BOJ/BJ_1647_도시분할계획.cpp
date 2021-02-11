//Kruskal
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int set[100001];

// 부모 노드를 가져옴 
int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

// 부모 노드를 병합 
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	// 더 숫자가 작은 부모로 병합
	if (a < b) set[b] = a;
	else set[a] = b;
}

// 같은 부모를 가지는지 확인
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

// 간선 클래스 선언 
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

vector<Edge> v;

int main() {
	int n, m;
	cin >> n >> m;

	// 거리의 합을 0으로 초기화 
	int sum = 0;
	int src, dst, weight;
	for (int i = 0; i < m; i++) {
		cin >> src >> dst >> weight;
		v.push_back({ src,dst,weight });
	}
	// 간선의 비용으로 오름차순 정렬 
	sort(v.begin(), v.end());

	// 각 정점이 포함된 그래프가 어디인지 저장 

	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	int b = n - 2;
	for (int i = 0; i < v.size(); i++) {
		// 동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택 
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			if (b == 0)break;
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
			b--;
		}
	}

	printf("%d\n", sum);

	return 0;
}