#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    int down_cnt = 0; // 내린 개수
    
    answer = m*n;
     
    do{
        down_cnt = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(board[i][j] == ' ')continue; // 빈 공간
                if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]){ // 폭발
                    v.push_back({i,j});
                    v.push_back({i,j+1});
                    v.push_back({i+1,j});
                    v.push_back({i+1,j+1});
                }
            }
        }

        int erase_num = 0;
        for(int i=0;i<v.size();i++){
            int r = v[i].first;
            int c = v[i].second;
            if(board[r][c] != ' ')erase_num++;
            board[r][c] = ' ';
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        for(int i=0;i<n;i++){ // col 단위로 내리기
            vector<int> save; // 저장

            for(int j=m-1;j>=0;j--){
                if(board[j][i] == ' ')continue; // 저장 안해도 됨
                save.push_back(board[j][i]);
            }

            // 내리기
            for(int j=0;j<save.size();j++){
                if(board[m-1-j][i] != save[j])down_cnt++;
                board[m-1-j][i] = save[j];
            }
            for(int j=m-1-save.size();j>=0;j--){
                board[j][i] = ' ';
            }
        }
    }while(down_cnt !=0);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] != ' ')answer--;
        }
    }

    
    return answer;
}
