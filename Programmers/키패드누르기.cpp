#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int keypad[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -2} };
pair<int, int> pos[10];

int dist(pair<int, int> cur, pair<int, int> next) {
    return abs(cur.first - next.first) + abs(cur.second - next.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = {3, 0}, right = {3, 2};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (keypad[i][j] < 0) continue;
            else {
                pos[keypad[i][j]] = {i, j};
            }
        }
    }
    int idx = 0;
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            left = pos[num];
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            right = pos[num];
        }
        else {
            int left_dist = dist(left, pos[num]);
            int right_dist = dist(right, pos[num]);

            printf("left dist %d, right dist %d\n", left_dist, right_dist);

            if (left_dist < right_dist) { 
                answer += "L"; 
                left = pos[num];
            }
            else if (left_dist > right_dist) { 
                answer += "R"; 
                right = pos[num];
            }
            else {
                if (hand == "left") {
                    answer += "L";
                    left = pos[num];
                }
                else {
                    answer += "R";
                    right = pos[num];
                }
            }
        }
        idx++;
    }

    return answer;
}
