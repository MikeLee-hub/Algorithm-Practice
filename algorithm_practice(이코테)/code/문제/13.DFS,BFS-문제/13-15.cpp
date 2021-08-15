// 13-15.특정 거리의 도시 찾기(p.339) (백준 18352번)

/*
	bfs로 depth k인 모든 node 출력
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m, k, x;
queue<int> que;
int depth[300002];
vector<int> vertex[300002];
vector<int> ans;
bool is_answer;

void bfs() {
	int next, d;
	int i, size;
	is_answer = false;
	memset(depth, 0, sizeof(int) * (n + 2));
	que.push(x);
	depth[x] = 1;
	while (1) {
		if (que.empty())
			break;
		x = que.front();
		que.pop();
		d = depth[x];
		if (d > k) {
			ans.push_back(x);
			continue;
		}
		size = vertex[x].size();
		for (i = 0; i < size; i++) {
			next = vertex[x][i];
			if (depth[next] == 0) {
				depth[next] = d + 1;
				que.push(next);
			}
		}
	}
	size = ans.size();
	if (size == 0)
		printf("-1");
	else {
		sort(ans.begin(), ans.end());
		for (i = 0; i < size; i++)
			printf("%d\n", ans[i]);
	}
}

int main() {
	int i;
	int a, b;
	scanf("%d %d %d %d", &n, &m, &k, &x);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vertex[a].push_back(b);
	}
	bfs();
}