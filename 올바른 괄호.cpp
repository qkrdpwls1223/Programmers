#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;
    bool answer = true;

    for (int i = 0; i < s.length(); i++) {
        if (stack.empty() && s[i] == ')') {
            answer = false;
            break;
        }
        else if (s[i] == ')' && stack.top() == '(') {
            stack.pop();
        }
        else if (s[i] == '(') {
            stack.push(s[i]);
        }
    }
    if (stack.empty() == false) answer = false;

    return answer;
}

bool solution2(string s)
{
    bool answer = true;

    int Open_Cnt = 0;
    int Close_Cnt = 0;

    if (s[0] == ')') return false;

    for (int i = 0; i < s.length(); i++) {
        if (Close_Cnt > 0 && s[i] == '(') {
            if (Open_Cnt != Close_Cnt) {
                answer = false;
                break;
            }
            Open_Cnt = 0;
            Close_Cnt = 0;
        }
        if (s[i] == '(') Open_Cnt++;
        else if (s[i] == ')') Close_Cnt++;
    }
    if (Open_Cnt != Close_Cnt) answer = false;

    return answer;
}

int main() {
    string s = "(())()";

    cout << solution(s);

	return 0;
}