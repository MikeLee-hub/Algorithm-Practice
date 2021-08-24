// 7-2. ��ǰ ã�� (p.197)

/*
	n list�� m list�� ���Ҹ� Ž���ϴ� ����
	sequence search�� �ϰ� �Ǹ� n * m�� �ð����⵵�� ����.
	���� �� binary search�� �ϰ� �Ǹ� n * log_n + m * log_n �� �ȴ�.
	���� binary search�� �� �����ϴ�.

	but n�� ������ ������ �����Ƿ�, count sort�� ����� �������� �����ϸ� n + m ���� ����
*/

/*
���� �Է�:
5
8 3 7 9 2
3
5 7 9

���� ���:
no yes yes
*/
#include <stdio.h>
#include <stdlib.h>

int n_list[1000005];
int n, m;

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

int binary_search_recurse(int n, int start, int end) {
	int middle;
	if (start > end)
		return -1;
	middle = (start + end) / 2;
	if (n_list[middle] > n)
		return binary_search_recurse(n, start, middle - 1);
	else if (n_list[middle] < n)
		return binary_search_recurse(n, middle + 1, end);
	else
		return middle;
}

int main() {
	int i;
	int lookingfor;
	int is_exist;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &n_list[i]);
	
	qsort(n_list, n, sizeof(int), comp);
	
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &lookingfor);
		is_exist = binary_search_recurse(lookingfor, 0, n - 1);
		if (is_exist == -1)
			printf("no ");
		else
			printf("yes ");
	}
	return 0;
}