#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            if ((i + 2) * (yellow/i + 2) == (brown + yellow)) {
                if (i >= yellow/i) {
                    answer = vector<int>{ i + 2, yellow/i + 2 };
                    break;
                }
                else {
                    answer = vector<int>{ yellow/i + 2, i + 2 };
                    break;
                }
            }
        }
    }
    return answer;
}
