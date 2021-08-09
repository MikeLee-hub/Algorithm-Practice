// 12-14. 외벽 점검(p.335)

/*
    무조건 dist가 높은 애들부터 출격해야 인원이 작아짐. (2가 할 수 있는건 3도 할 수 있음)
    한 사람의 점검 시작 지점은 무조건 weak point에서 시작하게끔 해도 무관.

    따라서 dist가 높은 친구부터 weak point 하나를 할당.
    그에 따른 커버 가능한 weak point 삭제.
    다음 dist 친구에 나머지 weak point 하나를 할당.
    그에 따른 커버 가능한 weak point 삭제.
    weak point가 사라지거나 사람이 없을 때까지 반복
    각 사람에 모든 weak point를 할당해볼 때까지 반복
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ans;

void dfs(int n, vector<int> weak, vector<int> dist, int depth) {
    vector<int> next_weak;
    int weak_len = weak.size();
    int i, j;
    int start, end;

    if (weak_len == 0) {
        if(ans < depth+1)
            ans = depth + 1;
        return;
    }

    if (ans >= depth)
        return;

    if (depth == -1)
        return;

    if (dist[depth] >= n) {
        ans = depth;
        return;
    }

    for (i = 0; i < weak_len; i++) {
        start = weak[i];
        end = (start + dist[depth]) % n;
        next_weak.clear();
        if (end > start) {
            for (j = 0; j < weak_len; j++) {
                if (start <= weak[j] && weak[j] <= end)
                    continue;
                next_weak.push_back(weak[j]);
            }
        }
        else {
            for (j = 0; j < weak_len; j++) {
                if (start <= weak[j] || weak[j] <= end)
                    continue;
                next_weak.push_back(weak[j]);
            }
        }
        dfs(n, next_weak, dist, depth - 1);
    }
    return;
}


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    int dist_len = dist.size();
    int start;
    ans = -1;
    sort(dist.begin(), dist.end());
    dfs(n, weak, dist, dist_len - 1);
    if (ans == -1)
        return ans;
    answer = dist_len - ans;
    return answer;
}


int main() {
    //vector<int> weak = { 1,5,6,10 };
    //vector<int> dist = { 1,2,3,4 };
    vector<int> weak = { 0,10,50,80,120,160 };
    vector<int> dist = { 1,10,5,40,30 };
    printf("%d", solution(200, weak, dist));
    return 0;
}