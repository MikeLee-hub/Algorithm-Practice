// 9-3. 미래도시

/*
	다익스트라 두 번 사용. (1->k는 1을 기준으로, k->x는 k를 기준으로)
	역방향 cost도 같기 때문에 k를 기준으로 dijkstra 한 번만 사용하는 풀이도 가능할듯!
*/

/*
예제 입력:
5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5

예제 출력:
3
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

bool path[102][102];
int n, m;

int dijkstra(int start, int end) {
	int visited[102];
	int c_cost, c_node;
	priority_queue<pair<int,int>> frontier;

	for (int i = 1; i <= n; i++)
		visited[i] = INT_MAX;

	frontier.push(make_pair(0, start));
	visited[start] = 0;

	while (!frontier.empty()) {
		c_cost = -1 * frontier.top().first;
		c_node = frontier.top().second;
		frontier.pop();
		if (c_node == end)
			return c_cost;
		if (visited[c_node] < c_cost)
			continue;

		c_cost++;
		for (int i = 1; i <= n; i++) {
			if (!path[c_node][i])
				continue;
			if (visited[i] > c_cost) {
				frontier.push(make_pair(-1 * c_cost, i));
				visited[i] = c_cost;
			}
		}
	}
	return -1;
}

int main() {
	int a, b;
	int x, k;
	int cost_k, cost_x;
	scanf("%d %d", &n, &m);

	// path init
	for (int i = 1; i <= n; i++) {
		memset(path[i], 0, sizeof(bool) * (n+1));
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		path[a][b] = true;
		path[b][a] = true;
	}

	scanf("%d %d", &x, &k);

	cost_k = dijkstra(1, k);
	if (cost_k == -1) {
		printf("-1\n");
		return 0;
	}

	cost_x = dijkstra(k, x);
	if (cost_x == -1) {
		printf("-1\n");
		return 0;
	}
	printf("%d", cost_k + cost_x);

	return 0;
}

