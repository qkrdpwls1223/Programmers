#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    while (1) {
            if (ceil(b / pow(2, answer)) == ceil(a / pow(2, answer))) {
                return answer;
            }
        answer++;
    }
}
