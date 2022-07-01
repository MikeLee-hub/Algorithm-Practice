// 17-39. 화성 탐사 (p.388) (백준 4485번)

/*
	dijkstra 사용.
*/
/*
예제 입력:
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
0

예제 출력:
Problem 1: 20
Problem 2: 19
Problem 3: 36
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n;
int board[127][127];
int drow[4] = { 0,1,0,-1 };
int dcol[4] = { 1,0,-1,0 };

void get_board() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}

int dijkstra_search() {
	int c_cost, c_row, c_col, n_cost, n_row, n_col;
	bool is_visited[127][127];
	priority_queue<pair<int, int>> frontier;

	for (int i = 0; i < n; i++)
		memset(is_visited[i], 0, sizeof(bool) * n);

	frontier.push(make_pair(-1 * board[0][0], 0));

	while (!frontier.empty()) {
		c_cost = -1 * frontier.top().first;
		c_row = frontier.top().second / n;
		c_col = frontier.top().second % n;
		frontier.pop();

		if (is_visited[c_row][c_col])
			continue;
		is_visited[c_row][c_col] = true;

		if (c_row == n - 1 && c_col == n - 1)
			return c_cost;

		for (int i = 0; i < 4; i++) {
			n_row = c_row + drow[i];
			n_col = c_col + dcol[i];

			if (n_row < 0 || n_row >= n || n_col < 0 || n_col >= n)
				continue;
			if (is_visited[n_row][n_col])
				continue;
			n_cost = c_cost + board[n_row][n_col];

			frontier.push(make_pair(-1 * n_cost, (n_row * n) + n_col));
		}
	}
	return -1;
}

int main() {
	int ans;
	int case_num = 1;

	while(1){
		scanf("%d", &n);
		if (n == 0)
			return 0;
		get_board();
		ans = dijkstra_search();
		printf("Problem %d: %d\n", case_num, ans);
		case_num++;
	}
}