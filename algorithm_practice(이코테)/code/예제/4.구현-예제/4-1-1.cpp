// 4-1. 상하좌우 (p.110)

/*
매번 좌표를 움직이며 가능한 좌표인지를 체크
O(n)
*/
#include <stdio.h>

int x, y;
int n;

void check_loc(int a, int b) {
	if (a < 1 || b < 1)
		return;
	if (a > n || b > n)
		return;
	x = a, y = b;
}

int main() {
	char c, tmp;

	x = y = 1;

	scanf("%d ", &n);

	while (1) {
		scanf("%c%c", &c, &tmp);
		if (c == 'R')
			check_loc(x + 1, y);
		else if (c == 'U')
			check_loc(x, y - 1);
		else if (c == 'L')
			check_loc(x - 1, y);
		else if (c == 'D')
			check_loc(x, y + 1);
		if (tmp == '\n')
			break;
	}
	printf("%d %d\n", x, y);
}