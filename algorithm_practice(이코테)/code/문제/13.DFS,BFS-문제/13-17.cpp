// 13-17. 경쟁적 전염(p.344) (백준 18405번)

/*
	bfs사용.
	초기 바이러스를 바이러스 번호 기준 오름차순으로 queue에 저장하고 bfs진행.
	s초(s depth)까지 bfs진행 후 원하는 좌표의 board값 출력
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int board[205][205];
int depth[205][205];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int s, x, y;
vector<pair<int, int>> virus_list[1005];


void bfs() {
	int i, j, l;
	int len;
	int x, y;
	int v, d;
	int new_x, new_y;
	queue<int> que_x;
	queue<int> que_y;

	for (i = 0; i < n; i++) 
		memset(depth, 0, sizeof(int) * n);

	for (i = 1; i <= k; i++) {
		len = virus_list[i].size();
		for (j = 0; j < len; j++) {
			x = virus_list[i][j].first;
			y = virus_list[i][j].second;
			que_x.push(x);
			que_y.push(y);
			depth[x][y] = 1;
		}
	}

	while (1) {
		if (que_x.empty())
			break;
		x = que_x.front();
		y = que_y.front();
		v = board[x][y];
		d = depth[x][y];
		que_x.pop();
		que_y.pop();
		if (d > s)
			break;
		for (i = 0; i < 4; i++) {
			new_x = x + dx[i];
			new_y = y + dy[i];
			if (new_x < 0 || new_x >= n)
				continue;
			if (new_y < 0 || new_y >= n)
				continue;
			if (board[new_x][new_y] != 0)
				continue;
			que_x.push(new_x);
			que_y.push(new_y);
			board[new_x][new_y] = v;
			depth[new_x][new_y] = d + 1;
		}
	}
	
}

int main() {
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] != 0) {
				virus_list[board[i][j]].push_back({ i,j });
			}
		}
	}
	scanf("%d %d %d", &s, &x, &y);
	bfs();
	printf("%d", board[x-1][y-1]);
}