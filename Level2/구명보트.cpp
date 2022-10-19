#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int last_idx = people.size() - 1;
    sort(people.begin(), people.end(), greater<int>());
    for (int i = 0; i <= last_idx; i++) {
        if (people[i] + people[last_idx] <= limit) {
            answer++;
            last_idx--;
        }
        else {
            answer++;
        }
    }
    return answer;
}
