#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = s;
    bool Capital = true;
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] == ' ') {
            Capital = true;
            continue;
        }

        if (Capital || answer[i] >= 48 && answer[i] <= 57) {
            if (answer[i] >= 97) answer[i] -= 32;
            Capital = false;
        }
        else {
            if (answer[i] <= 90) answer[i] += 32;
        }
    }
    return answer;
}