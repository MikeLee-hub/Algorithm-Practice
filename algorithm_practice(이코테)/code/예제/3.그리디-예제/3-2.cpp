// 3-2. 큰 수의 법칙(p.92)

#include <stdio.h>

int main() {
	int n, m, k;
	int tmp;
	int a1, a2;
	a1 = a2 = 0;

	scanf("%d %d %d", &n, &m, &k);

	scanf("%d", &a2);
	for (int i = 1; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp > a1) {
			if (tmp > a2) {
				a1 = a2;
				a2 = tmp;
			}
			else
				a1 = tmp;
		}
	}

	tmp = m / (k + 1);

	printf("%d", tmp * a1 + (m - tmp) * a2);
}
