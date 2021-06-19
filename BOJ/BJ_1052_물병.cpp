//
//  BJ_1052_물병.cpp
//  _Algorithm
//
//  Created by 황성현 on 2021/06/18.
//

#include <iostream>

using namespace std;

int N,K;

int main(){
    cin >> N >> K;
    
    int result;

    for (result = 0; ;result++){
        int cnt = 0;
        int tempN = N;

        while (tempN){
            if (tempN % 2)cnt++; // 합쳐지지 않음
            tempN /= 2;
        }
        
        if (cnt <= K)break;
        N++;
    }

    cout << result;
    
    return 0;
}
