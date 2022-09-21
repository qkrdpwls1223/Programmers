#include <string>
#include <vector>

using namespace std;

string to_binary(int num) {
    string s = "";
    while (num > 0) {
        if (num % 2 == 1) s = "1" + s;
        else s = "0" + s;
        num >>= 1;
    }
    return s;
}
vector<int> solution(string s) {
    vector<int> answer = { 0, 0 };
    string x = s;
    int del_zero = 0;

    while(x != "1") {
        int size = 0;
        for(auto& e : x) {
            if (e == '1') size++;
            else del_zero++;
        }
        x = to_binary(size);

        answer[0]++;
    }
    answer[1] = del_zero;
    return answer;
}
