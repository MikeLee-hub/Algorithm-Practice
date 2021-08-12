// 13-19. 연산자 끼워 넣기(p.349) (백준 14888번)

/*
	앞에 수부터 연산자를 하나씩 전부 끼워넣어서 계산
	dfs 수행
*/

#include <stdio.h>

int n;
int a[12];
int num[4];
int max_ans, min_ans;

void bfs(int depth, int ans) {
	int i;
	int new_ans;
	int result = 0;
	if (depth == n) {
		if (ans > max_ans)
			max_ans = ans;
		if (ans < min_ans)
			min_ans = ans;
		return;
	}
	for (i = 0; i < 4; i++) {
		if (num[i] > 0) {
			num[i]--;
			if (i == 0)
				new_ans = ans + a[depth];
			else if (i == 1)
				new_ans = ans - a[depth];
			else if (i == 2)
				new_ans = ans * a[depth];
			else if (i == 3)
				new_ans = ans / a[depth];
			bfs(depth + 1, new_ans);
			num[i]++;
		}
	}
	return;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 4; i++)
		scanf("%d", &num[i]);
	max_ans = -1000000000;
	min_ans = 1000000000;
	bfs(1, a[0]);
	printf("%d\n%d", max_ans, min_ans);
	return 0;
}