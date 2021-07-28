#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int nSize = numbers.size();
    int *mask = new int[nSize];
    for(int i=0; i< nSize;i++)mask[i]=0;
    for(int i= 1 ; i < (1 << nSize); i++){
        int sum = 0;
        for(int j=0;j<nSize;j++){
            if(i&(1<<j))sum += numbers[j];
            else sum -= numbers[j];
        }
        if(sum == target)answer++;
    }
    
    
    return answer;
}
