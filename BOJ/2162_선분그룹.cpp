#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

int parent[3001];
int group[3001];
int N;

class Point {
public:
    ll x, y;
    Point operator - (Point a) {
        return{ x - a.x, y - a.y };
    }
};

class Line {
public:
    Point src;
    Point dst;
    int group;

};

Line l[3001];

ll ccw(Point p1, Point p2) {
    ll ret = p1.x * p2.y - p1.y * p2.x;
    if (ret == 0) return 0;
    else if (ret > 0) return 1;
    else return -1;
}
ll ccw(Point p1, Point p2, Point p3) {
    return ccw(p2 - p1, p3 - p1);
}


//CCW(A, B, C)* CCW(A, B, D) <= 0 이면서 CCW(C, D, A) * CCW(C, D, B) <= 0 
bool determinant(Line l1, Line l2) {
    if (ccw(l1.src, l1.dst, l2.src) * ccw(l1.src, l1.dst, l2.dst) <= 0 &&
        ccw(l2.src, l2.dst, l1.src) * ccw(l2.src, l2.dst, l1.dst) <= 0) {
        if ((l1.src.x < l2.src.x && l1.src.x < l2.dst.x && l1.dst.x < l2.src.x && l1.dst.x < l2.dst.x) ||
            (l2.src.x < l1.src.x && l2.src.x < l1.dst.x && l2.dst.x < l1.src.x && l2.dst.x < l1.dst.x)) return false;
        if ((l1.src.y < l2.src.y && l1.src.y < l2.dst.y && l1.dst.y < l2.src.y && l1.dst.y < l2.dst.y) ||
            (l2.src.y < l1.src.y && l2.src.y < l1.dst.y && l2.dst.y < l1.src.y && l2.dst.y < l1.dst.y)) return false;
        return true;
    }
    return false;
}

int findParent(int i) {
    if (parent[i] == i)return i;
    else return parent[i] = findParent(parent[i]);
}

void unionParent(int a, int b) {
    int u = findParent(a);
    int v = findParent(b);
    if (u < v)parent[v] = u;
    else parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> l[i].src.x >> l[i].src.y >> l[i].dst.x >> l[i].dst.y;

    for (int i = 0; i < N; i++)
        parent[i] = i; //자기 자신으로 최상위 부모 초기화


    //겹치면 union
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            if (determinant(l[i], l[j])) {
                unionParent(i, j);
            }
        }

    for (int i = 0; i < N; i++)
        group[findParent(i)]++;

    int mx = -1, ct = 0;
    for (int i = 0; i < N; i++) {
        if (mx < group[i])
            mx = group[i];
        if (group[i] > 0) ct++;
    }
    cout << ct << '\n' << mx;

    return 0;
}