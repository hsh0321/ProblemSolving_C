
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char gender[1001];
int set[1001];
// 부모 노드를 가져옴

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
    bool operator<(Edge &edge) {
        return this->distance < edge.distance;
    }
};

int getParent(int set[], int x) {
    if(set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}

// 부모 노드를 병합
void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if(a < b) set[b] = a;
    else set[a] = b;
}

// 같은 부모를 가지는지 확인
int find(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if(a == b) return 1;
    else return 0;
}
 


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    int M;
    
    cin >> N >> M;
    
    vector<Edge> v;
    
    for(int i=1;i<=N;i++)
        cin >> gender[i];
    
    int src,dst,dist;
    for(int i=0;i<M;i++){
        cin >> src >> dst >> dist;
        if(gender[src] != gender[dst]){
            v.push_back(Edge(src,dst,dist));
        }
    }

    
    // 간선의 비용으로 오름차순 정렬
    sort(v.begin(),v.end());
    
    // 각 정점이 포함된 그래프가 어디인지 저장
    for(int i = 0; i < N; i++) {
        set[i] = i;
    }
    
    // 거리의 합을 0으로 초기화
    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        // 동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택
        if(!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].distance;
            unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }
    
    bool flag = true;
    int s = getParent(set, 0);
    for(int i=1;i<N;i++){
        if(s != getParent(set, i)){
            flag = false;
            break;
        }
    }
    
    if(!flag)cout << -1;
    else cout << sum;
}
