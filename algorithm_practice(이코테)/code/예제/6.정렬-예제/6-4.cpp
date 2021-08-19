// 6-4. �� �迭�� ���� ��ü (p.182)

/*
	a �迭�� b�迭�� ���� �� a�迭�� �ּڰ��� b�迭�� �ִ��� ��ü
	�� ������ k�� �ݺ�. �� a�迭�� �ּڰ��� b�迭�� �ִ񰪺��� ũ�ٸ� ��ü���� ����.

	stdlib.h�� qsort ���
*/

/*
���� �Է�:
5 3
1 2 5 4 3
5 5 6 6 5

���� ���:
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