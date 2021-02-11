#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for(;;){
        if(N == 1)break;
        if(N % 3 == 0)N /= 3;
        else if(N % 2 ==0){
            if((N-1)%3 == 0){
                N--;
                cnt++;
                continue;
            }
            N /= 2;
        }
        else N--;
        cnt++;
    }
    cout << cnt;

}
