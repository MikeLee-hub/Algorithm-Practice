// 13-16. 연구소(p.341) (백준 14502번)

/*
	makewall()함수를 재귀적으로 사용하여 벽 세개를 설치하는 모든 경우를 찾고
	각 경우의 수에서 dfs를 이용하여 안전하지 못 한 공간 체크
*/

using namespace std;

#include <stdio.h>
#include <string.h>

int board[10][10];
int is_checked[10][10];
int virus_x[12];
int virus_y[12];
int virus_n;

int n, m;
int ans;
int convert_n;
int min_conv;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y) {
	int i;
	int new_x;
	int new_y;
	for (i = 0; i < 4; i++) {
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (new_x < 0 || new_x >= n)
			continue;
		if (new_y < 0 || new_y >= m)
			continue;
		if (is_checked[new_x][new_y] == 0) {
			is_checked[new_x][new_y] = 2;
			convert_n++;
			dfs(new_x, new_y);
		}
	}
}

void makewall(int x, int y, int depth) {
	int i, j;
	if (depth == 3) {
		convert_n = 0;
		for (i = 0; i < n; i++)
			memcpy(is_checked[i], board[i], sizeof(int)*m);
		for (i = 0; i < virus_n; i++)
			dfs(virus_x[i], virus_y[i]);
		if (convert_n < min_conv)
			min_conv = convert_n;
		return;
	}
	for (j = y + 1; j < m; j++) {
		if (board[x][j] == 0) {
			board[x][j] = 1;
			makewall(x, j, depth + 1);
			board[x][j] = 0;
		}
	}
	for (i = x + 1; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				makewall(i, j, depth + 1);
				board[i][j] = 0;
			}
		}
	}
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	virus_n = 0;
	ans = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 2) {
				virus_x[virus_n] = i;
				virus_y[virus_n] = j;
				virus_n++;
			}
			if (board[i][j] == 0)
				ans++;
		}
	}
	ans -= 3;
	min_conv = ans;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				makewall(i, j, 1);
				board[i][j] = 0;
			}
		}
	}
	ans -= min_conv;
	printf("%d", ans);
}