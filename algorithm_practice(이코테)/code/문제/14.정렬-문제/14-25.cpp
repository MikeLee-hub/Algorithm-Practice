// 14-25. 실패율 (p.361) (2019 카카오 신입공채)

/*
    실패율과 stage number의 pair을 만든 후 정렬
    algorithm 헤더의 sort사용.
    내림차순과 오름차순이 섞인 sorting이므로 comp함수 직접 구현
*/

#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int s_num[505];

bool comp(pair<float, int> v1, pair<float, int> v2)
{
    if (v1.first > v2.first)
        return true;
    else if (v1.first < v2.first)
        return false;
    return v1.second < v2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> fail_rate;
    int i;
    int s_len = stages.size();
    float success;
    float tmp_rate;
    memset(s_num, 0, sizeof(int) * (N+2));

    for (i = 0; i < s_len; i++) {
        s_num[stages[i]]++;
    }

    success = s_num[N + 1];

    for (i = N; i > 0; i--) {
        success += s_num[i];
        if (success == 0)
            tmp_rate = 0;
        else
            tmp_rate = s_num[i] / success;
        fail_rate.push_back({ tmp_rate ,i });
    }
    sort(fail_rate.begin(), fail_rate.end(), comp);
    
    for (i = 0; i < N; i++)
        answer.push_back(fail_rate[i].second);
    return answer;
}

int main() {
    int N = 4;
    vector<int> stages = {4,4,4,4,4};
    stages = solution(N, stages);
    for (int i = 0; i < N; i++)
        printf("%d ", stages[i]);
}