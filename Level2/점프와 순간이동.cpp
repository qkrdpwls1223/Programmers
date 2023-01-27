#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    for (int i = n; i > 0; i /= 2) {
        if (i %2 == 1) ans++;
    }

    return ans;
}
