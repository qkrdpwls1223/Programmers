#include <iostream>
#include <string>
#include <stack>
using namespace std;


int solution3(string s) {
    stack<char> stack;
    
    for (auto& c : s) {
        if (!stack.empty() && stack.top() == c)
            stack.pop();
        else
            stack.push(c);
    }

    return stack.empty();
}

int main() {
    string s = "baabaa";
    string s2 = "cdcd";

    cout << solution3(s2);

    return 0;
}
