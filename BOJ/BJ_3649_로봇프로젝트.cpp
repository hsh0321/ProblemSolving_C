//
//  BJ_3649_로봇프로젝트.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/09/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x,n,l;
    while (cin >> x) {
        x *= 10000000;
        vector<int> v;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> l;
            v.push_back(l);
        }
        
        sort(v.begin(),v.end());
        
        int left = 0,right = n-1;
        bool flag = false;
        while(left<right){
            int sum = v[left] + v[right];
            if(sum == x){
                flag = true;
                break;
            }else if(sum > x){
                right--;
            }else{
                left++;
            }
        }
        
        if(flag){
            cout << "yes " << v[left] << " " << v[right] << endl;
        }else{
            cout << "danger" << endl;
        }
    }
    
    
    return 0;
}
