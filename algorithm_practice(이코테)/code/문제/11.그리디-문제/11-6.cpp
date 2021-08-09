// 11-6. 무지의 먹방 라이브 (p.316)
/*
    시간이 가장 적게 걸리는 음식부터 계산

*/
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long n, i, nn;
    long long l;
    vector<pair<int, int>> v;

    n = food_times.size();
    for (i = 0; i < n; i++) {
        v.push_back(pair<int, int>(food_times[i], i));
    }
    sort(v.begin(), v.end());

    nn = n;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            l = v[i].first * nn;
        }
        else {
            l = (v[i].first - v[i - 1].first) * nn;
        }

        if (l <= k) {
            k -= l;
            nn--;
            food_times[v[i].second] = 0;
            if (nn == 0)
                return -1;
        }
        else {
            k %= nn;
            break;
        }
    }

    while (food_times[answer] == 0) {
        answer++;
    }

    for (i = 0; i < k; i++) {
        answer++;
        while (food_times[answer] == 0) {
            answer++;
        }
    }

    return answer + 1;
}

int main() {
    vector<int> food_times = { 3, 1, 2 };
    printf("%d", solution(food_times, 5));
}