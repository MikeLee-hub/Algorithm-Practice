// 15 - 29. ������ ��ġ (p.369) (���� 2110��)

/*
	���� ������ �������� �Ÿ��� ���� �� �������� Ȯ��
	���� ������ �������� �Ÿ��� binary search�� Ž��
	�ð� : log x * n (30 * 200000)

	���� ������ n���� ���� �Ҵ��ϴ� ������� ������ Ǭ�ٸ�
	nCc - 200000! / 100000! / 100000! 
	�̱� ������ ���� binary search�� �ſ� ���� ����
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