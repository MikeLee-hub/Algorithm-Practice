// 13-18. 괄호 변환(p.346) (2020 카카오 신입 공채 코테)

/*
    문제에 주어진 알고리즘대로 구현
*/

#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    int len = p.length();
    int num1, num2;
    int i, j;
    bool is_right;
    string answer = "";
    string v;

    if (len == 0)
        return answer;

    num1 = 0;
    num2 = 0;
    is_right = true;
    for (i = 0; i < len; i++) {
        if (p[i] == '(')
            num1++;
        else if (p[i] == ')')
            num2++;
        if (num1 < num2)
            is_right = false;
        if (num1 == num2)
            break;
    }
    v = solution(p.substr(i + 1));
    if (is_right) {
        answer = p.substr(0, i+1) + v;
    }
    else {
        answer = "(";
        answer += v;
        answer.push_back(')');
        for (j = 1; j < i; j++) {
            if (p[j] == '(')
                answer.push_back(')');
            else
                answer.push_back('(');
        }
    }

    return answer;

}

int main() {
    string p = "()))((()";
    p = solution(p);
    return 0;
}