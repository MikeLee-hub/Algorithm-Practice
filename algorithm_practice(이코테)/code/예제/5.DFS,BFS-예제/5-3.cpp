// 5-3. 음료 얼려 먹기 (p.149)

/*
	dfs 이용.
*/

/*testcase*/
/*
4 5
00110
00011
11111
00000
=>3

15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111
=>8
*/
#include <stdio.h>

char board[1005][1005];
int n, m;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y) {
	int i;
	int new_x, new_y;
	if (board[x][y] != '0')
		return;
	board[x][y] = '2';
	for (i = 0; i < 4; i++) {
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (new_x >= 0 && new_x < n) {
			if (new_y >= 0 && new_y < m)
				dfs(new_x, new_y);
		}
	}
	return;
}

int main() {
	int i, j;
	int ans = 0;
	char c;
	scanf("%d %d ", &n, &m);

	for (i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (board[i][j] == '0') {
				ans++;
				dfs(i, j);
			}
		}
	}
	printf("%d", ans);
}