//
//  BJ_17135_캐슬디펜스.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[16][16],tmp[16][16];
int N,M,D;

class cmp{
public:
    bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        if(a.first == b.first)return (a.second.second > b.second.second);
        return a.first > b.first;
    }
};

int dist(pair<int,int> a, pair<int,int> b){
    int len = abs(a.first-b.first) + abs(a.second - b.second);
    return len;
}

         
int main(){
    cin >> N >> M >> D;

    int numOfEnemy = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> tmp[i][j];
            
            if(tmp[i][j])numOfEnemy++;
        }
    }
    
    vector<int> v;
    for(int i=0;i<M-3;i++)v.push_back(0);
    for(int i=0;i<3;i++)v.push_back(1);
    
    int answer = 0;
    
    do{
        //초기화
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                map[i][j] = tmp[i][j];
        
        
        int cnt = 0; // 잡은 수
        int flag = numOfEnemy; // 남아있는 적 수
        
        vector<int> archer;
        
        for(int i=0;i<v.size();i++){
            if(v[i])archer.push_back(i);
        }
        
        
        while(flag != 0){
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq[3]; // d , x,y
            for(int a=0;a<archer.size();a++){
                for(int i=N-1;i>=0;i--){
                    for(int j=0;j<M;j++){
                        if(map[i][j]){ // 적 일때
                            int d = dist({i,j},{N,archer[a]});
                            if(d <= D){ // 사정거리 안
                                pq[a].push({d,{i,j}});
//                                cnt++;
//                                flag--;
                            }
                        }
                    }
                }
            }
            
            for(int a=0;a<archer.size();a++){
                if(!pq[a].empty()){ // 잡을 수 있는 적이 있음
                    pair<int,int> p = pq[a].top().second;
                    if(map[p.first][p.second] == 0)continue; // 이미 다른 아쳐가 잡음
                    map[p.first][p.second] = 0;
                    cnt++;
                    flag--;
                }
            }
            
            //            cout << "after kill " << endl;
            //            for(int i=0;i<N;i++){
            //                for(int j=0;j<M;j++){
            //                    cout << map[i][j] << " ";
            //                }
            //                cout << endl;
            //            }
            
            for(int i=0;i<M;i++){
                if(map[N-1][i])flag--;
            }
            
            for(int i=N-1;i>0;i--){
                for(int j=0;j<M;j++){
                    map[i][j] = map[i-1][j];
                }
            }
            //            cout << "after down " << endl;
            //            for(int i=0;i<N;i++){
            //                for(int j=0;j<M;j++){
            //                    cout << map[i][j] << " ";
            //                }
            //                cout << endl;
            //            }
            
            for(int i=0;i<M;i++)map[0][i] = 0;
        }
        answer = max(answer,cnt);
    }while(next_permutation(v.begin(), v.end()));
    
    cout << answer << endl;
    
    return 0;
}
