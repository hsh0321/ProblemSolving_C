#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string word){
	int answer = 0;
	int mul[5] = { 1, 5, 25, 125, 625 };
	map<char, int> m = { {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4} };
	for (int i = 0; i < word.size(); i++){
		answer += 1;
		for (int j = 0; j < m[word[i]]; j++){
			for (int k = 4; k >= i; k--){
				answer += mul[4 - k];
			}
		}
	}
	return answer;
}
