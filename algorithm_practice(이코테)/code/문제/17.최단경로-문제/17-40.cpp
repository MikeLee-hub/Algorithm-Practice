// 17-40. 숨바꼭질 (p.390) (백준 6118번)

/*
	dijkstra 끝까지 돌려서 최대 최단거리 구하기.
*/

/*
예제 입력:
6 7
3 6
4 3
3 2
1 3
1 2
2 4
5 2

예제 출력:
4 2 3
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n;
int ans, max_dist, ans_count;
vector<int> board[20002];

void dijkstra_search() {
	int c_dist, c_node, n_dist, n_node;
	bool is_visited[20002];
	int tmp;
	queue<pair<int, int>> frontier;

	memset(is_visited, 0, sizeof(bool) * (n+1));

	frontier.push(make_pair(0, 1));
	max_dist = -1; 
	ans = -1;
	ans_count = -1;

	while (!frontier.empty()) {
		c_dist = -1 * frontier.front().first;
		c_node = frontier.front().second;
		frontier.pop();

		if (is_visited[c_node])
			continue;
		is_visited[c_node] = true;

		if (c_dist > max_dist) {
			max_dist = c_dist;
			ans = c_node;
			ans_count = 1;
		}
		else {
			ans_count++;
			if (c_node < ans)
				ans = c_node;
		}

		n_dist = c_dist + 1;
		
		tmp = board[c_node].size();
		for (int i = 0; i < tmp; i++) {
			n_node = board[c_node][i];
			if (is_visited[n_node])
				continue;

			frontier.push(make_pair(-1 * n_dist, n_node));
		}
	}
	return;
}

int main() {
	int m;
	int a, b;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		board[a].push_back(b);
		board[b].push_back(a);
	}
	
	dijkstra_search();
	printf("%d %d %d\n", ans, max_dist, ans_count);

	return 0;
}