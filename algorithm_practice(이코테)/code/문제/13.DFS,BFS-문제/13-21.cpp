// 13-21. 인구 이동(p.353) (백준 16234번)

/*
	bfs를 사용하여 같은 연합을 체크.
	연합개수 == 나라개수이면 출력 후 프로그램 종료
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int n, l, r;
int board[55][55];

int group[55][55];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void bfs(int x, int y, int group_n) {
	queue<int> que_x;
	queue<int> que_y;
	vector<pair<int, int>> group_mem;
	int group_p;
	int nation_n;
	int new_x, new_y, pop, new_pop;
	int i;
	int sub;

	que_x.push(x);
	que_y.push(y);
	group[x][y] = group_n;
	group_p = board[x][y];
	nation_n = 1;
	group_mem.push_back({ x,y });

	while (!que_x.empty()) {
		x = que_x.front();
		y = que_y.front();
		que_x.pop();
		que_y.pop();
		pop = board[x][y];
		for (i = 0; i < 4; i++) {
			new_x = x + dx[i];
			new_y = y + dy[i];
			if (new_x < 0 || new_x >= n)
				continue;
			if (new_y < 0 || new_y >= n)
				continue;
			if (group[new_x][new_y] != 0)
				continue;
			new_pop = board[new_x][new_y];
			sub = abs(pop - new_pop);
			if (sub > r || sub < l)
				continue;
			nation_n++;
			group_p += new_pop;
			group[new_x][new_y] = group_n;
			que_x.push(new_x);
			que_y.push(new_y);
			group_mem.push_back({ new_x,new_y });
		}
	}

	group_p /= nation_n;

	for (i = 0; i < nation_n; i++)
		board[group_mem[i].first][group_mem[i].second] = group_p;

}

bool move_cycle() {
	int i, j;
	int group_n = 0;
	for (i = 0; i < n;i++)
		memset(group[i], 0, sizeof(int) * n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (group[i][j] == 0) {
				group_n++;
				bfs(i, j, group_n);
			}
		}
	}
	if (group_n == n * n)
		return true;
	return false;
}

int main() {
	int i, j;
	scanf("%d %d %d", &n, &l, &r);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (i = 0;; i++) {
		if (move_cycle())
			break;
	}

	printf("%d", i);
	return 0;
}