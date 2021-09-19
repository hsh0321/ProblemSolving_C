//
//  BJ_17143_낚시왕.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/09/19.
//

#include <iostream>
using namespace std;

int map[101][101];

struct SHARK{
    int r, c;
    int s, d, z;
    bool isdead;
}shark[10001];

int dr[] = { 0,-1,1,0,0 };
int dc[] = { 0,0,0,1,-1 };

int main(void){
    int ans = 0;
    int r, c, m;
    
    cin >> r >> c >> m;
    
    for (int i = 1; i <= m; i++){
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        map[shark[i].r][shark[i].c] = i;
    }
    
    
    for (int t = 1; t <= c; t++){
        //사냥
        for (int k = 1; k <= r; k++){
            if (map[k][t] != 0){
                //v번째 상어가 있다면,
                shark[map[k][t]].r = -1;
                shark[map[k][t]].c = -1;
                shark[map[k][t]].isdead = true;
                ans += shark[map[k][t]].z;
                map[k][t] = 0;
                break;
            }
        }
        
        
        //이동
        for (int i = 1; i <= m; i++){
            if (shark[i].isdead) continue;
            
            if (shark[i].d == 1 || shark[i].d == 2){
                shark[i].s = shark[i].s % (2 * r - 2);
                
                int nr = shark[i].r + shark[i].s*dr[shark[i].d];
                
                while (nr <1 || nr >r){
                    if (nr > r){
                        nr = 2 * r - nr;
                        shark[i].d = 1;
                    }else if (nr < 1){
                        nr = (1 - nr) + 1;
                        shark[i].d = 2;
                    }
                }
                shark[i].r = nr;
                
            }else{
                shark[i].s = shark[i].s % (2 * c - 2);
                
                int nc = shark[i].c + shark[i].s*dc[shark[i].d];
                
                while (nc <1 || nc >c){
                    if (nc > c){
                        nc = 2 * c - nc;
                        shark[i].d = 4;
                    }else if (nc < 1){
                        nc = (1 - nc) + 1;
                        shark[i].d = 3;
                    }
                }
                shark[i].c = nc;
                
            }
        }
        
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                map[i][j] = 0;
        
        for (int i = 1; i <= m; i++){
            if (!shark[i].isdead){
                if (map[shark[i].r][shark[i].c] == 0){
                    map[shark[i].r][shark[i].c] = i;
                }else{
                    if(shark[map[shark[i].r][shark[i].c]].z < shark[i].z){
                        //내가 더크면,
                        shark[map[shark[i].r][shark[i].c]].c = -1;
                        shark[map[shark[i].r][shark[i].c]].r = -1;
                        shark[map[shark[i].r][shark[i].c]].isdead = true;
                        map[shark[i].r][shark[i].c] = i;
                    }else{
                        //내가 더 작으면
                        shark[i].c = shark[i].r = -1;
                        shark[i].isdead = true;
                    }
                }
            }
        }
    }
    
    cout << ans;
    
    
    return 0;
}
