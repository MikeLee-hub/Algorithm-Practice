// 6-4. 두 배열의 원소 교체 (p.182)

/*
	a 배열과 b배열을 정렬 후 a배열의 최솟값과 b배열의 최댓값을 교체
	위 동작을 k번 반복. 단 a배열의 최솟값이 b배열의 최댓값보다 크다면 교체하지 않음.

	stdlib.h의 qsort 사용
*/

/*
예제 입력:
5 3
1 2 5 4 3
5 5 6 6 5

예제 출력:
26
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compa(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

int compb(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}

int main() {
	int n, k;
	int i;
	int a[100005];
	int b[100005];
	unsigned long long sum = 0;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	qsort(a, n, sizeof(int), compa);
	qsort(b, n, sizeof(int), compb);

	for (i = 0; i < k; i++) {
		if (b[i] <= a[i])
			break;
		sum -= a[i];
		sum += b[i];
	}
	printf("%lld", sum);
	return 0;
}