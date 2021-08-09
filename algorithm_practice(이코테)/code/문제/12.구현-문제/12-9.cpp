// 12-9. 문자열 압축(p.323)

/*
	string subset을 반복적으로 사용하며 수행. but 더 좋은 방법이 있어보임.
    O(n^2)
*/
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer;
    int len = s.length();
    int halflen = len / 2 + 1;
    int tmp_ans;
    int i, j;
    int is_changed;
    string base;
    string comp;
    answer = len;

    for (i = 1; i <= halflen; i++) {
        j = 0;
        tmp_ans = len;
        while (j <= len - i) {
            base = s.substr(j, i);
            j += i;
            is_changed = 0;
            while (j <= len - i) {
                comp = s.substr(j, i);
                if (base.compare(comp))
                    break;
                is_changed++;
                j += i;
                tmp_ans -= i;
            }
            if (is_changed)
                is_changed++;
            while(is_changed > 0){
                tmp_ans += 1;
                is_changed /= 10;
            }
        }
        if (answer > tmp_ans)
            answer = tmp_ans;
    }

    return answer;
}

int main() {
    string s = "aaaaaaaaaaaaaaabbbbbbbbbbc";

    printf("%d", solution(s));
}