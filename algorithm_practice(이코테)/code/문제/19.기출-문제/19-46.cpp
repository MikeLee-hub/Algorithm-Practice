// 19-46. 아기상어 (p.402) (백준 16236번)

/*
	bfs. 먹이를 못 찾을 때까지 반복적으로 돌려보기.
*/

/*
예제입력:
3
0 0 0
0 0 0
0 9 0

예제출력:
0

*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, ans;
int shark_size;
int eat_stack;
int board[22][22];
int start_x, start_y;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int bfs() {
	int i, j;
	int new_i, new_j;
	int dist = 0;
	int visit[22][22];
	queue<pair<int, int>> frontier;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = -1;
		}
	}

	frontier.push(make_pair(start_x, start_y));
	visit[start_x][start_y] = ans;

	while (!frontier.empty()) {
		i = frontier.front().first;
		j = frontier.front().second;
		frontier.pop();

		if (board[i][j] > 0 && board[i][j] < shark_size) {	// i가 작은 거 우선. 그 후 x
			ans = visit[i][j];
			start_x = i;
			start_y = j;
			while (!frontier.empty()) {
				i = frontier.front().first;
				j = frontier.front().second;
				frontier.pop();
				if (visit[i][j] > ans)
					break;
				if (board[i][j] <= 0 || board[i][j] >= shark_size)
					continue;
				if (i < start_x) {
					start_x = i;
					start_y = j;
				}
				else if (i == start_x && j < start_y) {
					start_x = i;
					start_y = j;
				}
			}
			eat_stack++;
			if (eat_stack == shark_size) {
				shark_size++;
				eat_stack = 0;
			}
			board[start_x][start_y] = 0;
			
			return 1;
		}

		for (int k = 0; k < 4; k++) {
			new_i = i + dx[k];
			new_j = j + dy[k];
			if (new_i < 0 || new_i >= n)
				continue;
			if (new_j < 0 || new_j >= n)
				continue;
			if (visit[new_i][new_j] >= 0)
				continue;
			if (board[new_i][new_j] > shark_size)
				continue;
			visit[new_i][new_j] = visit[i][j] + 1;
			frontier.push(make_pair(new_i, new_j));
		}
	}
	return 0;
}

int main() {

	scanf("%d", &n);
	ans = 0;
	shark_size = 2;
	eat_stack = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 9) {
				start_x = i;
				start_y = j;
				board[i][j] = 0;
			}
		}
	}

	while (bfs());

	printf("%d", ans);

}