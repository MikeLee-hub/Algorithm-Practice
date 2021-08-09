// 12-11. 뱀(p.327)

/*
	걍 board에 뱀을 계속 찍고 지우고 반복을 단순 구현
	이차원 struct 배열을 만드는게 조금 더 깔끔했을 수도
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int change_num;				// 방향 변하기
int change_time[103];
char change_direc[103];

int board[105][105];		// 게임판  ( 0 : nothing, 1 : snake, 2 : apple )

int tail_x, tail_y;			// 꼬리위치 (꼬리 지우는데 사용)
int snake_direc[105][105];	// 뱀의 방향기록(tail지우는데 사용) 0 : (x, y--), 1 : (x--,y), 2 : (x, y++), 3 : (x++, y)
int n;						// 보드의 크기

int dx[4] = { 0,-1,0,1 };	// 다음 머리 좌표 dx
int dy[4] = { -1,0,1,0 };	// 다음 머리 좌표 dy

int is_valid(int x, int y) {
	if (x <= 0 || x > n)
		return 0;
	if (y <= 0 || y > n)
		return 0;
	if (board[x][y] == 1)
		return 0;
	return 1;
}

int mov(int x, int y, int time, int direction) {	// 재귀
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