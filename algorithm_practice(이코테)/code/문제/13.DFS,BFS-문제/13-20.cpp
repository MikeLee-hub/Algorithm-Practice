// 13-20. 감시 피하기(p.351) (백준 18428번)

/*
	깊이 3짜리 재귀로 dfs를 돌려 모든 장애물을 놓는 경우를 구하고
	각각 경우에서 student가 보이는 teacher가 존재하는지 확인
	student가 보이는 teacher가 없으면 YES를 출력하고 프로그램 종료.
	있으면 다음 경우 확인
	모든 경우의 수에 대해 모두 student가 보이는 teacher가 존재한다면 NO출력 후 프로그램 종료
*/

#include <stdio.h>
#include <stdlib.h>

char board[8][8];
int n;

bool check_teacher(int x, int y) {
	int i;
	for (i = x+1; i < n; i++) {
		if (board[i][y] == 'W')
			break;
		if (board[i][y] == 'T')
			break;
		if (board[i][y] == 'S')
			return false;
	}
	for (i = x-1; i >= 0; i--) {
		if (board[i][y] == 'W')
			break;
		if (board[i][y] == 'T')
			break;
		if (board[i][y] == 'S')
			return false;
	}
	for (i = y-1; i >= 0; i--) {
		if (board[x][i] == 'W')
			break;
		if (board[x][i] == 'T')
			break;
		if (board[x][i] == 'S')
			return false;
	}
	for (i = y+1; i < n; i++) {
		if (board[x][i] == 'W')
			break;
		if (board[x][i] == 'T')
			break;
		if (board[x][i] == 'S')
			return false;
	}
	return true;
}

void check_ans() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] == 'T') {
				if (!check_teacher(i, j))
					return;
			}
		}
	}
	printf("YES");
	exit(0);
}

void make_wall(int depth, int x, int y) {
	int i, j;

	if (depth == 3) {
		check_ans();
		return;
	}

	for (j = y; j < n; j++) {
		if (board[x][j] == 'X') {
			board[x][j] = 'W';
			make_wall(depth + 1, x, j + 1);
			board[x][j] = 'X';
		}
	}
	for (i = x + 1; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] == 'X') {
				board[i][j] = 'W';
				make_wall(depth + 1, i, j + 1);
				board[i][j] = 'X';
			}
		}
	}
}


int main() {
	int i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	make_wall(0, 0, 0);
	printf("NO");
	return 0;
}