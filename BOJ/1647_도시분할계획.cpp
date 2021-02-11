//Kruskal
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int set[100001];

// �θ� ��带 ������ 
int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

// �θ� ��带 ���� 
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	// �� ���ڰ� ���� �θ�� ����
	if (a < b) set[b] = a;
	else set[a] = b;
}

// ���� �θ� �������� Ȯ��
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

// ���� Ŭ���� ���� 
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

	// �Ÿ��� ���� 0���� �ʱ�ȭ 
	int sum = 0;
	int src, dst, weight;
	for (int i = 0; i < m; i++) {
		cin >> src >> dst >> weight;
		v.push_back({ src,dst,weight });
	}
	// ������ ������� �������� ���� 
	sort(v.begin(), v.end());

	// �� ������ ���Ե� �׷����� ������� ���� 

	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	int b = n - 2;
	for (int i = 0; i < v.size(); i++) {
		// ������ �θ� ����Ű�� �ʴ� ���, �� ����Ŭ�� �߻����� ���� ���� ���� 
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