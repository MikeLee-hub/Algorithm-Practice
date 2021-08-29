// 15 - 29. 공유기 설치 (p.369) (백준 2110번)

/*
	가장 인접한 공유기의 거리를 선택 후 가능한지 확인
	가장 인접한 공유기의 거리를 binary search로 탐색
	시간 : log x * n (30 * 200000)

	집에 공유기 n개를 먼저 할당하는 방식으로 문제를 푼다면
	nCc - 200000! / 100000! / 100000! 
	이기 때문에 차이 binary search가 매우 많이 유리
*/

#include <stdio.h>
#include <stdlib.h>

int n, c;
int x[200005];

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

int is_possible(int min_dist) {
	int i;
	int before = x[0];
	int count = c-1;

	for (i = 1; i < n; i++) {
		if (x[i] - before >= min_dist) {
			count--;
			before = x[i];
			if (count == 0)
				return 1;
		}
	}
	return 0;
}

int search(int start, int end) {
	int middle;

	while (start <= end) {
		middle = (start + end) / 2;
		if (is_possible(middle))
			start = middle + 1;
		else
			end = middle - 1;
	}
	return end;
}

int main() {
	int i;
	scanf("%d %d", &n, &c);

	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	qsort(x, n, sizeof(int), comp);

	printf("%d", search(1, 1000000000));
}