// 12-11. ��(p.327)

/*
	�� board�� ���� ��� ��� ����� �ݺ��� �ܼ� ����
	������ struct �迭�� ����°� ���� �� ������� ����
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int change_num;				// ���� ���ϱ�
int change_time[103];
char change_direc[103];

int board[105][105];		// ������  ( 0 : nothing, 1 : snake, 2 : apple )

int tail_x, tail_y;			// ������ġ (���� ����µ� ���)
int snake_direc[105][105];	// ���� ������(tail����µ� ���) 0 : (x, y--), 1 : (x--,y), 2 : (x, y++), 3 : (x++, y)
int n;						// ������ ũ��

int dx[4] = { 0,-1,0,1 };	// ���� �Ӹ� ��ǥ dx
int dy[4] = { -1,0,1,0 };	// ���� �Ӹ� ��ǥ dy

int is_valid(int x, int y) {
	if (x <= 0 || x > n)
		return 0;
	if (y <= 0 || y > n)
		return 0;
	if (board[x][y] == 1)
		return 0;
	return 1;
}

int mov(int x, int y, int time, int direction) {	// ���
	int new_x;
	int new_y;
	int tmp_d;

	if (board[x][y] == 2);
	else if (board[tail_x][tail_y] == 1) {
		board[tail_x][tail_y] = 0;
		tmp_d = snake_direc[tail_x][tail_y];
		tail_x += dx[tmp_d];
		tail_y += dy[tmp_d];
	}

	if (time == change_time[change_num]) {
		if (change_direc[change_num] == 'L') {
			direction--;
			if (direction == -1)
				direction = 3;
		}
		else if (change_direc[change_num] == 'D') {
			direction++;
			if (direction == 4)
				direction = 0;
		}
		change_num++;
	}
	snake_direc[x][y] = direction;
	board[x][y] = 1;

	new_x = x + dx[direction];
	new_y = y + dy[direction];
	
	if (!is_valid(new_x, new_y))
		return time + 1;

	return mov(new_x, new_y, time + 1, direction);

}

int main() {
	int i;
	int x, y;
	int apple_n;

	scanf("%d", &n);
	for (i = 0; i <= n; i++)
		memset(board[i], 0, sizeof(int) * (n + 1));

	scanf("%d", &apple_n);
	for (i = 0; i < apple_n; i++) {
		scanf("%d %d", &x, &y);
		board[x][y] = 2;
	}

	scanf("%d", &change_num);
	for (i = 0; i < change_num; i++) 
		scanf("%d %c", &change_time[i], &change_direc[i]);
	change_time[change_num] = -1;
	change_num = 0;

	tail_x = 1;
	tail_y = 1;
	snake_direc[1][1] = 3;
	printf("%d\n", mov(1, 1, 0, 2));

}