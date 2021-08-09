// 12-14. �ܺ� ����(p.335)

/*
    ������ dist�� ���� �ֵ���� ����ؾ� �ο��� �۾���. (2�� �� �� �ִ°� 3�� �� �� ����)
    �� ����� ���� ���� ������ ������ weak point���� �����ϰԲ� �ص� ����.

    ���� dist�� ���� ģ������ weak point �ϳ��� �Ҵ�.
    �׿� ���� Ŀ�� ������ weak point ����.
    ���� dist ģ���� ������ weak point �ϳ��� �Ҵ�.
    �׿� ���� Ŀ�� ������ weak point ����.
    weak point�� ������ų� ����� ���� ������ �ݺ�
    �� ����� ��� weak point�� �Ҵ��غ� ������ �ݺ�
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