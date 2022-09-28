#include <string>
#include <vector

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0, 0 };
    
    for(int i = 1; i < words.size(); i++) {
        if (words[i-1].back() != words[i].front()) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
        for (int j = 0; j < i; j++) {
            if (words[i].compare(words[j]) == 0) {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                return answer;
            }
        }
    }

    return answer;
}
