#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<int> nums;

    string num;
    while (getline(ss, num, ' ')) {
        nums.push_back(stoi(num));
    }
    return to_string(*min_element(nums.begin(), nums.end())) + " " + to_string(*max_element(nums.begin(), nums.end()));
}

int main() {
    string s = "1 2 3 4";

    cout << solution(s);
}