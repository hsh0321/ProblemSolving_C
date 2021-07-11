#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
class Car{
    public:
    int r,c,cost, dir;
};
 
int answer = 999999999;
int dr[] = {0,1,0,-1}, dc[] = {1,0,-1,0};

int solution(vector<vector<int>> board) {
    int N = board.size();
    
    queue<Car> q;    
    Car c;
    c.r = 0, c.c = 0, c.cost = 0, c.dir = 0;
    q.push(c);
    c.dir = 1;
    q.push(c);
    board[0][0] = 1;
    
    while(!q.empty()){
        Car a = q.front();
        q.pop();
        if(a.r == N - 1 && a.c == N - 1){
            if(answer > a.cost) answer = a.cost;
            continue;
        }
        for(int i=0;i<4;i++){
            int nr = a.r + dr[i];
            int nc = a.c + dc[i];
            
            if(nr<0 || nc<0 || nr>=N || nc>=N) continue;
            if(board[nr][nc] == 1)continue;
            
            int val = 0;
            
            if(a.dir == i)val = a.cost + 100;
            else if(a.dir != i)val = a.cost + 600;
            
            if(board[nr][nc] == 0 || board[nr][nc] >= val){
                board[nr][nc] = val;
                Car p;
                p.r = nr, p.c = nc, p.cost = val, p.dir = i;
                q.push(p);
            }
        }
        
    }
    return answer;
}
