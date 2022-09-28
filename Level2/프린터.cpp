#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void print_v(vector<int> v) {
    int i;
    cout << "[ ";
    for (i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[i] << " ]\n";
}
void print_v(vector<pair<int, int>> v) {
    int i;
    cout << "[ ";
    for (i = 0; i < v.size() - 1; i++) {
        cout << "<" << v[i].first << "," << v[i].second << ">, ";
    }
    cout << "<" << v[i].first << "," << v[i].second << "> ]\n";
}
void back(vector<int>& v, int idx) {
    int tmp = v[idx];

    for (int i = idx + 1; i < v.size(); i++) {
        v[i - 1] = v[i];
    }
    v[v.size() - 1] = tmp;
}
void back(vector<pair<int,int>>& v, int idx) {
    pair<int,int> tmp = v[idx];

    for (int i = idx + 1; i < v.size(); i++) {
        v[i - 1] = v[i];
    }
    v[v.size() - 1] = tmp;
}
void back2(vector<int>& v, int idx) {
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i <= idx; i++) {
        v1.push_back(v[i]);
    }
    for (int i = idx + 1; i < v.size(); i++) {
        v2.push_back(v[i]);
    }
    print_v(v1);
    print_v(v2);
    v2.reserve(v1.size() + v2.size());
    v2.insert(v2.end(), v1.begin(), v1.end());
    v = v2;
}

int solution(vector<int> priorities, int location) {
    //테스트 2 7 8 10 11 13 16 17 18 19 실패
    int answer = location;
    for (int i = location + 1; i < priorities.size(); i++) {
        if (priorities[location] < priorities[i]) {
            answer = priorities.size() - i + location - 1;
            break;
        }
    }
    for (int i = 0; i < location; i++) {
        if (location != i && priorities[location] >= priorities[i]) {
            answer--;
        }
    }
    return answer + 1;
}

int solution2(vector<int> priorities, int location) {
    int point = location + 1;
    print_v(priorities);

    for (int i = 0; i < priorities.size(); i++) {
        for (int j = i + 1; j < priorities.size(); j++) {
            if (priorities[i] < priorities[j]) {
                cout << "i - " << i << " j - " << j << '\n';
                back(priorities, i);
                print_v(priorities);
                if (point == i) point = priorities.size() - 1;
                else if (point > i) point--;
                i--;
                break;
            }
        }
    }
    cout << "-----------------------\n";

    return point;
}
int solution2_2(vector<int> priorities, int location) {
    vector<pair<int, int>> vv;

    for (int i = 0; i < priorities.size(); i++) {
        vv.push_back(make_pair(priorities[i], (location == i) ? 1 : 0));
    }

    for (int i = 0; i < vv.size(); i++) {
        for (int j = i + 1; j < vv.size(); j++) {
            if (vv[i].first < vv[j].first) {
                back(vv, i);
                i--;
                break;
            }
        }
    }
    for (int i = 0; i < vv.size(); i++) {
        if (vv[i].second) return i + 1;
    }
}

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
int solution3(vector<int> priorities, int location) {
    vector<pair<int, int>> vv;
    for (int i = 0; i < priorities.size(); i++) {
        vv.push_back(make_pair(priorities[i], i));
    }
    print_v(vv);
    sort(vv.begin(), vv.end(), comp);
    print_v(vv);

    for (int i = 0; i < vv.size(); i++) {
        if (vv[i].second == location) return i + 1;
    }

}

int main() {
    vector<int> priorities = { 2, 1, 3, 2 };
    int location = 2;

    cout << solution2_2(priorities, location) << endl;

    vector<int> priorities2 = { 1, 1, 2, 3, 2, 1 };
    int location2 = 0;

    cout << solution2_2(priorities2, location2) << endl;

    return 0;
}

//어렵당.... 큐로 못풀겟슴,,,,,,, 그냥 sort쓰면은 뒤로 밀리는거 땜시 안됐고
//몬가 첨에 생각은 맞게 한것같은데 길을 좀 잘못 들어버린 느낌 맵을 쓸까 하다가 페어라는 걸 원래도 알고 있었지만
//이번에 제대로 쓸 수 있게 된 느낌? 저번에는 그냥 보고 적었으면 지금은 알아서 쓰는느낌
//근데 블로그 언제 만들지 여기다 적을게 아니라 빨리 정리해야하는데 존나 귀찮다..........
//근데 for문이 많아서 효율적일지는 모르겠다
