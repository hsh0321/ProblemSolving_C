#include <iostream>
#include <queue>
using namespace std;
 
int N;
long long arr[10000010];

int main(){
    cin >> N;
    queue<long long> q;
    for (int i = 1; i <= 9; i++){
        q.push(i);
        arr[i] = i;
    }

    int idx = 10;
    while (idx <= N && !q.empty()){
        long long num = q.front();
        q.pop();
 
        int last = num % 10;
        for (int i = 0; i < last; i++){
            q.push(num * 10 + i);
            arr[idx++] = num * 10 + i;
        }
    }
    
    if (idx >= N && arr[N] != 0)cout << arr[N] << endl;
    else{
        if(N == 0)cout << 0 << endl;
        else cout << -1 << endl;
    }
 
    return 0;
}
