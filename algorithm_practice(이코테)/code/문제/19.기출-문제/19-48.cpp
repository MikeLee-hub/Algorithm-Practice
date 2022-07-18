// 19-48. 어른상어 (p.408) (백준 19237 번)

/*
	단순 시뮬레이션 구현
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;

int board[22][22][2];			// 위치와 냄새 정보. [i][j][0] : 상어 종류, [i][j][0] : 남은 시간
pair<int, int> shark[405];		// 상어 위치
int direction[405];				// 현재 상어 방향
int moving_rule[405][4][4];		// 움직임 우선순위 규칙
int ans;
int survived_n;					// 2~m상어 중 살아남은 수

int dx[4] = { -1,1,0,0 };		// 상하좌우 순. 사용법 : dx[moving_rule[n][direction[n]][i]
int dy[4] = { 0,0,-1,1 };		// 상하좌우 순

void decreasing_smell() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j][1] < 0)
				board[i][j][1] = k + 1;
			if (board[i][j][1])
				board[i][j][1]--;
		}
	}
}

void simulate() {
	bool next_decided, killed;
	int next_x, next_y, next_direction;

	for (int i = 0; i < m; i++) {
		next_decided = false;
		killed = false;
		if (shark[i].first < 0)
			continue;

		for (int j = 0; j < 4; j++) {	// 주변에 냄새 없는 칸이 존재하는 경우
			next_direction = moving_rule[i][direction[i]][j];
			next_x = shark[i].first + dx[next_direction];
			next_y = shark[i].second + dy[next_direction];
			if (next_x >= n || next_x < 0)
				continue;
			if (next_y >= n || next_y < 0)
				continue;
			if (board[next_x][next_y][1] > 0)
				continue;
			next_decided = true;
			if (board[next_x][next_y][1] < 0) {		// 죽는 경우
				killed = true;
				shark[i].first = -1;
				survived_n--;
			}
			break;
		}
		if (killed)
			continue;

		if (!next_decided) {	// 주변에 냄새 없는 칸이 존재하지 않는 경우
			for (int j = 0; j < 4; j++) {
				next_direction = moving_rule[i][direction[i]][j];
				next_x = shark[i].first + dx[next_direction];
				next_y = shark[i].second + dy[next_direction];
				if (next_x >= n || next_x < 0)
					continue;
				if (next_y >= n || next_y < 0)
					continue;
				if (board[next_x][next_y][0] != i)
					continue;
				break;
			}
		}

		board[next_x][next_y][0] = i;
		if (board[next_x][next_y][1] > 0)		// 내 냄새로 가는 경우 이후 상어 접근 X
			board[next_x][next_y][1] = k + 1;
		else
			board[next_x][next_y][1] = -1;		// 냄새 없는 곳으로 가는 경우 이후 상어들이 죽으러 옴
		shark[i].first = next_x;
		shark[i].second = next_y;
		direction[i] = next_direction;
	}
	decreasing_smell();
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j][0]);
			if (board[i][j][0]) {
				board[i][j][0]--;
				shark[board[i][j][0]] = make_pair(i, j);
				board[i][j][1] = k;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &direction[i]);
		direction[i]--;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d %d %d", &moving_rule[i][j][0], &moving_rule[i][j][1], &moving_rule[i][j][2], &moving_rule[i][j][3]);
			moving_rule[i][j][0]--;
			moving_rule[i][j][1]--;
			moving_rule[i][j][2]--;
			moving_rule[i][j][3]--;
		}
	}

	survived_n = m - 1;
	ans = 0;
	while (survived_n && ans <= 1000) {
		simulate();
		ans++;
	}
	if (ans > 1000)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}