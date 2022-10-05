#include <string>
#include <vector>

using namespace std;

int Howmany_one(int num) {
    int one = 0;
    while (num > 0) {
        if (num % 2 == 1) one++;
        num >>= 1;
    }
    return one;
}

int solution(int n) {
    for (int answer = n + 1; ; answer++) {
        if (Howmany_one(answer) == Howmany_one(n)) return answer;
    }
}

//      비트로만 풀려고 하면 이 규칙을 사용해보면 될 것 같다.
//
//10011100011     이렇게 있으면
//10011100101     마지막 0뒤에 있는 1과 자리를 바꾼다.
//                그럼 다음 큰 숫자가 된다.
//
//111110000       1앞에 0이 없어서 자리를 바꿀수 없다면
//1011110000      제일 앞에 있는 1일 제외한 첫번째 1에 0을 추가해주면 된다.
//
//
//100111100       1이 여러개일 땐
//101011100       일단 마지막 0을(뒤에 바꿀 1이 있는) 찾아서 뒤에있는 1과 자리를 바꾼다.
//101000011       나머지 11은 다 뒤로 밀어버린다.
//
//                찾은 규칙대로 구현해보려 했으나 제일 먼저 생각난(위에 알고리즘)보다 빠를 것 같지 않고 코드가 보다 복잡해져서 굳이 구현해보진 않았음
