#include <iostream>
using namespace std;
int N,K;
int gain[51];
int answer = 0;
bool visit[51];
int weight = 500;
 
void dfs(int count){
    if(count==N) {
        answer++;
    }
    else{
        for(int i=0; i<N; i++){
            if(!visit[i]){
                visit[i]=true;
                if(weight+gain[i]>=500){
                    weight += gain[i];
                    dfs(count+1);
                    weight -= gain[i];
                    visit[i]=false;
                }
                else
                    visit[i]=false;
 
            }
        }
    }
}
 
 
int main(void){
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>gain[i];
        gain[i]-=K;
    }
    dfs(0);
    cout<<answer;
 
}
