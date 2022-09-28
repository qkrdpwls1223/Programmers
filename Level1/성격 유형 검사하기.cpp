#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int RT[2] = { 0, 0 }, CF[2] = { 0, 0 }, JM[2] = { 0, 0 }, AN[2] = { 0, 0 };

    for(int i = 0; i < survey.size(); i++) {
        if (survey[i] == "RT") {
            if (choices[i] <= 3) {
                RT[0] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                RT[1] += choices[i] - 4;
            }
        }
        else if (survey[i] == "TR") {
            if (choices[i] <= 3) {
                RT[1] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                RT[0] += choices[i] - 4;
            }
        }
        else if (survey[i] == "CF") {
            if (choices[i] <= 3) {
                CF[0] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                CF[1] += choices[i] - 4;
            }
        }
        else if (survey[i] == "FC") {
            if (choices[i] <= 3) {
                CF[1] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                CF[0] += choices[i] - 4;
            }
        }
        else if (survey[i] == "JM") {
            if (choices[i] <= 3) {
                JM[0] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                JM[1] += choices[i] - 4;
            }
        }
        else if (survey[i] == "MJ") {
            if (choices[i] <= 3) {
                JM[1] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                JM[0] += choices[i] - 4;
            }
        }
        else if (survey[i] == "AN") {
            if (choices[i] <= 3) {
                AN[0] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                AN[1] += choices[i] - 4;
            }
        }
        else if (survey[i] == "NA") {
            if (choices[i] <= 3) {
                AN[1] += 4 - choices[i];
            }
            else if (choices[i] >= 5) {
                AN[0] += choices[i] - 4;
            }
        }
    }

    if (RT[0] >= RT[1]) {
        answer += "R";
    }
    else if (RT[0] < RT[1]) {
        answer += "T";
    }
    
    if (CF[0] >= CF[1]) {
        answer += "C";
    }
    else if (CF[0] < CF[1]) {
        answer += "F";
    }
    
    if (JM[0] >= JM[1]) {
        answer += "J";
    }
    else if (JM[0] < JM[1]) {
        answer += "M";
    }
    
    if (AN[0] >= AN[1]) {
        answer += "A";
    }
    else if (AN[0] < AN[1]) {
        answer += "N";
    }
    
    return answer;
}
