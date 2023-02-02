#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int island_check(vector<string>& maps, int X, int Y) {
    if (maps[X][Y] != 'X') {
        int sum = maps[X][Y] - 48;
        maps[X][Y] = 'X';

        if (Y+1 < maps[0].length()) {
            if (maps[X][Y+1] != 'X')
                sum += island_check(maps, X, Y+1);
        }
        if (X+1 < maps.size()) {
            if (maps[X+1][Y] != 'X')
                sum += island_check(maps, X+1, Y);
        }
        if (Y > 0) {
            if (maps[X][Y-1] != 'X')
                sum += island_check(maps, X, Y-1);
        }
        if (X > 0) {
            if (maps[X-1][Y] != 'X')
                sum += island_check(maps, X-1, Y);
        }
        
        return sum;
    }
    else
        return 0;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].length(); j++) {
            if (maps[i][j] != 'X') {
                int sum = island_check(maps, i, j);
                if (sum > 0) answer.push_back(sum);
            }
        }
    }
    if (answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}
