//
//  BJ_16927_배열돌리기2.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/09/02.
//

#include <iostream>
#include <algorithm>
using namespace std;

int arr[301][301];

int main(){
    int N,M,R;
    
    cin >> N >> M >> R;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<min(N,M)/2;i++){
        int cycle = R % (2*N + 2*M - 8*i - 4);

        for(int j=0;j<cycle;j++){
            int tmp = arr[i][i];
            
            // up
            for(int k=i+1;k<M-i;k++)
                arr[i][k-1] = arr[i][k];
            
            // right
            for(int k=i+1;k<N-i;k++)
                arr[k-1][M-i-1] = arr[k][M-i-1];
            
            // down
            for(int k=M-i-1;k>i;k--)
                arr[N-i-1][k] = arr[N-i-1][k-1];
            
            // left
            for(int k=N-i-1;k>i;k--)
                arr[k][i] = arr[k-1][i];
            
            arr[i+1][i] = tmp;
            

        }
    }
    
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
