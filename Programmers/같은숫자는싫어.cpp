#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++){
        if(i < arr.size()-1 && arr[i] != arr[i+1]){

            answer.push_back(arr[i]);
        }
    }
    answer.push_back(arr[arr.size()-1]);

    return answer;
}
