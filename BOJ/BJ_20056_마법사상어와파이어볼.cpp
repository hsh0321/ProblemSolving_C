#include <iostream>
#include <vector>

using namespace std;
int N,M,K,ans;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int oddEvenDir[] = {0,2,4,6};
int elseDir[] = {1,3,5,7};

class info{
public:
    int r, c, weight, speed, dir;
};

vector<info> fireBalls;
vector<info> board[51][51];

void moveFireBall(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            board[i][j].clear();

    for(int i = 0; i < fireBalls.size(); i++){
        int x = fireBalls[i].r;
        int y = fireBalls[i].c;
        int weight = fireBalls[i].weight;
        int speed = fireBalls[i].speed;
        int dir = fireBalls[i].dir;
        int move = speed % N;

        int nx = x + dx[dir] * speed;
        int ny = y + dy[dir] * speed;
        // 맵 범위 밖
        if (nx > N) nx -= N;
        if (ny > N) ny -= N;
        if (nx < 1) nx += N;
        if (ny < 1) ny += N;
        fireBalls[i].r = nx;
        fireBalls[i].c = ny;
        board[nx][ny].push_back({ nx,ny,weight,speed,dir });
    }
}

void sumAndDivBalls(){
    vector<info> tmp;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (board[i][j].size() == 0) continue; // 파이어볼 없음
            if (board[i][j].size() == 1){
                tmp.push_back(board[i][j][0]);
                continue;
            }
            
            int weightSum = 0; // 무게합
            int speedSum = 0; // 속도합
            int ballsCnt = board[i][j].size(); // 개수
 
            bool isEven = true;
            bool isOdd = true;
            
            for (int k = 0; k < board[i][j].size(); k++){
                weightSum += board[i][j][k].weight;
                speedSum += board[i][j][k].speed;
                if (board[i][j][k].dir % 2 == 0) isOdd = false;
                else isEven = false;
            }
            
            int m = weightSum / 5;
            int s = speedSum / ballsCnt;
            if (!m) continue;
            if (isEven == true || isOdd == true){
                for (int k = 0; k < 4; k++) tmp.push_back({ i, j, m, s, oddEvenDir[k] });
            }
            else{
                for (int k = 0; k < 4; k++) tmp.push_back({ i, j, m, s, elseDir[k] });
            }
        }
    }
    fireBalls = tmp;
}


int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        fireBalls.push_back({r,c,m,s,d});
        board[r][c].push_back({r,c,m,s,d});
    }

    while(K--){
        moveFireBall();
        sumAndDivBalls();
    }

    for(int i = 0; i < fireBalls.size(); i++){
        ans += fireBalls[i].weight;
    }
    
    cout << ans << endl;
}
