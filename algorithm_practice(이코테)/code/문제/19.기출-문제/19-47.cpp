// 19-47. 청소년상어 (p.406) (백준 19236 번)

/*
	모든 경우의 수를 다 계산해야할듯.
	브르투포스 bfs.
*/


#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };			// 0 :위 방항. 이후 반시계로 회전.(1는 위좌, 2는 좌...)
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int position[17][2];								// position[n] : n+1번째 물고기의 좌표. n=0은 shark. 값이 -1이면 먹힌상태.
int direction[17];									// position[n] : n+1번째 물고기의 방향
int board[4][4];									// board[i][j] : (i,j)에 있는 물고기 번호. shark는 0번. 비면 -1번

void swap(int a, int b) {
	int tmp_x, tmp_y;
	tmp_x = position[a][0];
	tmp_y = position[a][1];
	position[a][0] = position[b][0];
	position[a][1] = position[b][1];
	position[b][0] = tmp_x;
	position[b][1] = tmp_y;
	board[position[a][0]][position[a][1]] = a;
	board[position[b][0]][position[b][1]] = b;
}

void simulate() {
	int next_x, next_y;
	for (int i = 1; i <= 16; i++) {
		if (position[i][0] == -1)
			continue;
		for (int j = 0; j <= 8; j++) {
			next_x = position[i][0] + dx[direction[i]];
			next_y = position[i][1] + dy[direction[i]];
			if (next_x < 0 || next_x >= 4 || next_y < 0 || next_y >= 4) {
				direction[i]++;
				direction[i] %= 8;
				continue;
			}
			else if (board[next_x][next_y] == 0) {
				direction[i]++;
				direction[i] %= 8;
				continue;
			}
			if (board[next_x][next_y] == -1) {
				board[position[i][0]][position[i][1]] = -1;
				board[next_x][next_y] = i;
				position[i][0] = next_x;
				position[i][1] = next_y;
			}
			else
				swap(i, board[next_x][next_y]);
			break;
		}
	}
}

int bfs(int shark_size, int x, int y) {
	int new_x, new_y;
	int ans;
	int ate_num;
	int tmp_pos[17][2];
	int tmp_dir[17];
	int tmp_board[4][4];


	for (int i = 0; i < 17; i++) {
		tmp_pos[i][0] = position[i][0];
		tmp_pos[i][1] = position[i][1];
		tmp_dir[i] = direction[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			tmp_board[i][j] = board[i][j];
	}

	if (board[x][y] == 0);
	else {
		ate_num = board[x][y];
		board[position[0][0]][position[0][1]] = -1;
		position[0][0] = x;
		position[0][1] = y;
		direction[0] = direction[ate_num];
		position[ate_num][0] = -1;
		board[x][y] = 0;
		shark_size += ate_num;
	}
	ans = shark_size;
	simulate();


	new_x = position[0][0];
	new_y = position[0][1];
	for (int i = 0; i < 4; i++) {
		new_x += dx[direction[0]];
		new_y += dy[direction[0]];
		if (new_x < 0 || new_x >= 4 || new_y < 0 || new_y >= 4) {
			break;
		}
		if (board[new_x][new_y] == -1)
			continue;
		ans = max(ans, bfs(shark_size, new_x, new_y));
	}

	for (int i = 0; i < 17; i++) {
		position[i][0] = tmp_pos[i][0];
		position[i][1] = tmp_pos[i][1];
		direction[i] = tmp_dir[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			board[i][j] = tmp_board[i][j];
	}
	return ans;
}


int main() {
	int n, d;
	int ans;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d", &n, &d);
			position[n][0] = i;
			position[n][1] = j;
			direction[n] = d - 1;
			board[i][j] = n;
		}
	}
	position[0][0] = 0;
	position[0][1] = 0;
	direction[0] = direction[board[0][0]];
	position[board[0][0]][0] = position[board[0][0]][1] = -1;
	ans = board[0][0];
	board[0][0] = 0;
	printf("%d", bfs(ans, 0, 0));;
}