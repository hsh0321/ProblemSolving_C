//
//  BJ_21608_상어초등학교.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/05/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[21][21];
int student[401][4];
int answer = 0;

int dr[4] = {1,-1,0,0},dc[4] = {0,0,1,-1};

class Student{
public:
    int r,c;
    int near = 0,empty = 0;
};

bool cmp(Student s1, Student s2){
    if(s1.near == s2.near){
        if(s1.empty == s2.empty){
            if(s1.r == s2.r){
                return s1.c < s2.c; // 열번호 내림차순
            }
            return s1.r < s2.r; // 행번호 내림차순
        }
        return s1.empty > s2.empty; // 비어있는 칸
    }
    return s1.near > s2.near; // 선호 학생 수
}

void findLoc(int* s){
    vector<Student> v;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] != 0)continue; // 이미 학생이 있음
            Student tmp;
            tmp.r = i; tmp.c = j;
            int nr,nc;
            for(int k=0;k<4;k++){ // 4방위 체크
                nr = tmp.r + dr[k];
                nc = tmp.c + dc[k];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N)continue; // 맵 밖
                if(map[nr][nc] == s[1]
                   || map[nr][nc] == s[2]
                   || map[nr][nc] == s[3]
                   || map[nr][nc] == s[4]){
                    tmp.near++; // 선호 학생
                }else if(map[nr][nc] == 0){
                    tmp.empty++; // 빈 공간
                }
            }
            v.push_back(tmp);
        }
    }
    
    sort(v.begin(),v.end(),cmp);
    map[v[0].r][v[0].c] = s[0];
    

}

int main(){
    cin >> N;
    
    int s[5];
    for(int i=0;i<N*N;i++){
        cin >> s[0];
        for(int j=1;j<5;j++){
            cin >> s[j];
            student[s[0]][j-1] = s[j];
        }
        
        findLoc(s);
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int nr,nc;
            int cnt = 0;
            for(int k=0;k<4;k++){
                nr = i + dr[k];
                nc = j + dc[k];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N)continue; // 맵 밖
                if(map[nr][nc] == student[map[i][j]][0]
                   || map[nr][nc] == student[map[i][j]][1]
                   || map[nr][nc] == student[map[i][j]][2]
                   || map[nr][nc] == student[map[i][j]][3]){
                    cnt++;
                }
            }
            
            switch (cnt) {
                case 1:
                    answer += 1;
                    break;
                case 2:
                    answer += 10;
                    break;
                case 3:
                    answer += 100;
                    break;
                case 4:
                    answer += 1000;
                    break;
            }
        }
    }
    
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            cout << map[i][j] << ' ';
//        }
//        cout << endl;
//    }
    
    
    
    cout << answer;
    return 0;
}
