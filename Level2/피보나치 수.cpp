#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    long long x = 0;
    long long y = 1;
    for (int i = 2; i <= n; i++) {
        cout << x << " " << y << " ";
        long long tmp = x;
        x = y % 1234567;
        y = (tmp + y) % 1234567;
    }
    return y % 1234567;
}
// 1234567은 뭔뜻일까.... 왤까.... 오버플로우 때문인건 알겠는데 왜지.....?
int main() {
    int n = 1500;
    int result = 1058440;
    int sol = solution(n);
    cout << sol << endl;
}
