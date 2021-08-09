// 5-4. 미로 탈출 (p.152)

/*
	bfs 이용.
*/

/*
5 6
101010
111111
000001
111111
111111
*/

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int n, m;
char board[205][205];
int is_visited[205][205];

queue<int> que_x;
queue<int> que_y;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int bfs() {
	int x, y;
	int depth;
	int new_x, new_y;
	int i;

	que_x.push(0);
	que_y.push(0);
	is_visited[0][0] = 1;

	while (1) {
		x = que_x.front();
		que_x.pop();
		y = que_y.front();
		que_y.pop();
		depth = is_visited[x][y];

		for (i = 0; i < 4; i++) {
			new_x = x + dx[i];
			new_y = y + dy[i];
			if (new_x >= 0 && new_x < n) {
				if (new_y >= 0 && new_y < m) {
					if (new_x == n - 1 && new_y == m - 1)
						return depth + 1;
					if (board[new_x][new_y] == '1' && is_visited[new_x][new_y] == 0) {
						is_visited[new_x][new_y] = depth+1;
						que_x.push(new_x);
						que_y.push(new_y);
					}
				}
			}
		}
	}
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", board[i]);
		memset(is_visited[i], 0, sizeof(int) * (m + 2));
	}

	printf("%d", bfs());
	return 0;
}