#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, right = 0;
    vector<long long> tree;

    cin >> n >> m;
    for(int i=0; i<n; i++){
        long long tmp;
        cin >> tmp;
        tree.push_back(tmp);
        right = max(right, tmp);
    }
 
    long long mid = right / 2, left = 0, answer = 0;
    
    while(right >= left){
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(tree[i] > mid) sum += tree[i] - mid;
        }
        if(sum >= m){
            if(answer < mid) answer = mid;
            left = mid + 1;
        }
        else{
            right = mid-1;
        }
        mid = (left + right) / 2;
    }
    cout << answer;
    
    return 0;
}
