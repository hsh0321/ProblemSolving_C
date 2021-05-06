#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 101

int H, W;
char arr[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector <pair <int, int>> point;

int bfs(int init_x, int init_y) {
    queue<pair<pair<int, int>, pair<int, int>>> que;
    visit[init_x][init_y] = 0;
    
    for (int i = 0; i < 4; i++)
        que.push(make_pair(make_pair(init_x, init_y), make_pair(i, 0)));
    
    while (!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int Direction = que.front().second.first;
        int count = que.front().second.second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next_count = count;

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (arr[nx][ny] == '*') continue;
            if (Direction != i) next_count = count + 1;
            if (visit[nx][ny] == -1 || visit[nx][ny] >= next_count) {
                visit[nx][ny] = next_count;
                que.push(make_pair(make_pair(nx, ny), make_pair(i, next_count)));
            }
        }
    }
    return visit[point[1].first][point[1].second];
}



int main() {

    cin >> W >> H;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C')
                point.push_back(make_pair(i, j));
        }
    }
    memset(visit, -1, sizeof(visit));

    cout << bfs(point[0].first, point[0].second);
    return 0;
}
