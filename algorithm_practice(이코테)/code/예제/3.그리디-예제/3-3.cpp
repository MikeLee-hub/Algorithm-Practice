// 3-3. 숫자 카드 게임(p.96)
#include <stdio.h>

int main() {
	int n, m;
	int i, j;
	int tmpn, tmpm;
	int tmp;

	scanf("%d %d", &n, &m);

	tmpm = 0;

	for (i = 0; i < n; i++) {
		tmpn = 10001;
		for (j = 0; j < m; j++) {
			scanf("%d", &tmp);
			if (tmp < tmpn)
				tmpn = tmp;
		}
		if (tmpn > tmpm)
			tmpm = tmpn;
	}
	printf("%d\n", tmpm);
}