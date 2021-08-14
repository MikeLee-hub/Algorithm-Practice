// 13-20. ���� ���ϱ�(p.351) (���� 18428��)

/*
	���� 3¥�� ��ͷ� dfs�� ���� ��� ��ֹ��� ���� ��츦 ���ϰ�
	���� ��쿡�� student�� ���̴� teacher�� �����ϴ��� Ȯ��
	student�� ���̴� teacher�� ������ YES�� ����ϰ� ���α׷� ����.
	������ ���� ��� Ȯ��
	��� ����� ���� ���� ��� student�� ���̴� teacher�� �����Ѵٸ� NO��� �� ���α׷� ����
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