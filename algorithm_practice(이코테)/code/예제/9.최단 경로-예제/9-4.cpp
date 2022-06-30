// 9-4. 전보

/*
	다익스트라 알고리즘 사용.
	is_visited 배열을 이용하여 갯수 파악. 최종 시간은 마지막으로 node를 찾은 시간을 저장.
*/

/*
예제 입력:
3 2 1
1 2 4
1 3 2

예제 출력:
2 4
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> path[30002];
int n, m, c;
int max_cost, ans;

void dijkstra() {
	int visited[30002];
	int c_cost, c_node;
	int n_cost;

	priority_queue<pair<int, int>> frontier;

	for (int i = 1; i <= n; i++)
		visited[i] = INT_MAX;

	frontier.push(make_pair(0, c));
	visited[c] = 0;

	while (!frontier.empty()) {
		c_cost = -1 * frontier.top().first;
		c_node = frontier.top().second;
		frontier.pop();
		if (visited[c_node] < c_cost)
			continue;
		max_cost = c_cost;
		for (int n_node = 1; n_node <= n; n_node++) {
			if (path[c_node][n_node] == INT_MAX)
				continue;
			n_cost = c_cost + path[c_node][n_node];
			if (visited[n_node] > n_cost) {
				frontier.push(make_pair(-1 * n_cost, n_node));
				visited[n_node] = n_cost;
			}
		}
	}
	ans = -1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] != INT_MAX)
			ans++;
	}
	return;
}

int main() {
	int x, y, z;

	scanf("%d %d %d", &n, &m, &c);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			path[i].push_back(INT_MAX);
		path[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		path[x][y] = z;
	}

	dijkstra();
	printf("%d %d\n", ans, max_cost);
}

