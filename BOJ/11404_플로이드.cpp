#include <iostream>
#include <algorithm>
using namespace std;

#define INF 9999999

int n, m;
int arr[101][101];

void floyd_warshall() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (arr[j][i] != INF && arr[i][k] != INF)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
        }
    }
    int src, dst, weight;

    for (int i = 0; i < m; i++) {
        cin >> src >> dst >> weight;
        if (arr[src][dst] > weight)
            arr[src][dst] = weight;
    }
    floyd_warshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
