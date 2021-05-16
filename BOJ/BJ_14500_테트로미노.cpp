#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int map[510][510];
int sum[510][510];

int maxSum(int x,int y){
    int block[19];
    block[0] = map[y][x] + map[y][x+1] + map[y][x+2] + map[y][x+3];
    block[1] = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x];
    
    block[2] = map[y][x] + map[y + 1][x] + map[y][x+1] + map[y + 1][x+1];
    
    block[3] = map[y][x] + map[y + 1][x] + map[y+2][x] + map[y + 2][x + 1];
    block[4] = map[y][x] + map[y][x+1] + map[y][x+2] + map[y + 1][x];
    block[5] = map[y][x] + map[y][x+1] + map[y + 1][x+1] + map[y + 2][x + 1];
    block[6] = map[y+1][x] + map[y + 1][x+1] + map[y + 1][x+2] + map[y][x + 2];
    block[7] = map[y][x+1] + map[y + 1][x+1] + map[y + 2][x+1] + map[y + 2][x];

    block[8] = map[y][x] + map[y][x+1] + map[y][x+2] + map[y + 1][x + 2];
    block[9] = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x + 1];
    block[10] = map[y][x] + map[y + 1][x] + map[y + 1][x+1] + map[y + 1][x + 2];
    
    block[11] = map[y][x] + map[y+1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
    block[12] = map[y+1][x] + map[y + 1][x+1] + map[y][x + 1] + map[y][x + 2];
    block[13] = map[y][x+1] + map[y + 1][x+1] + map[y + 1][x] + map[y + 2][x];
    block[14] = map[y][x] + map[y][x+1] + map[y + 1][x + 1] + map[y + 1][x + 2];
    
    block[15] = map[y][x] + map[y][x+1] + map[y + 1][x + 1] + map[y][x + 2];
    block[16] = map[y][x+1] + map[y + 1][x+1] + map[y + 1][x] + map[y + 2][x + 1];
    block[17] = map[y][x+1] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
    block[18] = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x];
    
    int maxCase = 0;
    for (int i = 0; i < 19; i++) {
        maxCase = max(block[i], maxCase);
    }
    
    return maxCase;
}


int main(){
    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    
    int answer=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            sum[i][j] = maxSum(j,i);
            answer = max(answer,sum[i][j]);
        }
    }
    
    cout << answer << '\n';
}
