//
//  BJ_1613_역사.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/07/12.
//

#include <iostream>
#include <cstring>
 
using namespace std;
 
int n, k, s;
 
int mat[401][401];
 
void floyd(){
    for(int m=1; m<=n; m++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(mat[i][m] == mat[m][j] && mat[i][j] == 0) mat[i][j] = mat[i][m];
            }
        }
    }
}
 
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    memset(mat, 0, sizeof(mat));
    
    cin >> n >> k;
    
    // 연관된 사건 입력 받기
    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        mat[a][b] = -1;
        mat[b][a] = 1;
    }
    
    floyd();
    
    // 원하는 사건 출력
    cin >> s;
    for(int i=0; i<s; i++){
        cin >> a >> b;
        cout << mat[a][b] << "\n";
    }
}
