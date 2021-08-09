// 4-3. 게임개발 (p.119)

/*
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char board[52][52];
int is_checked[52][52];
int ans;

int turn_left_a(int a, int d) { // list로 구현가능
	if (d == 1)
		return a - 1;
	if (d == 3)
		return a + 1;
	return a;
}

int turn_left_b(int b, int d) { // list로 구현가능
	if (d == 0)
		return b - 1;
	if (d == 2)
		return b + 1;
	return b;
}

int turn_left_d(int d) {
	d--;
	if (d < 0)
		d = 3;
	return d;
}

void print_ans() {
	printf("%d", ans);
	exit(0);
}

void mov(int a, int b, int d) {
	int i;
	int next_a, next_b;
	int back_a, back_b, back_d;
	is_checked[a][b] = 1;
	
	for (i = 0; i < 4; i++) {
		next_a = turn_left_a(a, d);
		next_b = turn_left_b(b, d);
		d = turn_left_d(d);
		if (board[next_a][next_b] == '0' && is_checked[next_a][next_b] == 0) {
			ans++;
			mov(next_a, next_b, d);
			return;
		}
		if (i == 2) { // dx, dy 리스트를 사용할 경우 필요 없는 부분
			back_a = next_a;
			back_b = next_b;
			back_d = d;
		}
	}
	if (board[back_a][back_b] == '0')
		mov(back_a, back_b, back_d);
	else
		print_ans();


	return;
}

int main() {
	int a, b, d;
	ans = 1;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &a, &b, &d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf(" %c", &board[i][j]);
		memset(is_checked[i], 0 , sizeof(int)*(m+1));
	}

	mov(a, b, d);  // 어짜피 끝나는 순간 즉시 exit(0)할건데 굳이 재귀를 써야하나?
}