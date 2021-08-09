// 11-4. ���� �� ���� �ݾ� (p.314)

/*
1~n��° coin���� k���� ���� �� ������,
1~n+1��° coin���δ� value(n+1) ~ k + value(n+1)���� ���� �� �ִ�.

���⼭ value(n+1)�� k+1���� ũ�� k+1�� ���� ����� ����.
*/
#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);//��������
}

int coin[1005];
int total;

int main() {
	int i;
	int target;

	scanf("%d", &total);
	for (i = 0; i < total; i++)
		scanf("%d", &coin[i]);

	qsort(coin, total, sizeof(int), comp);
	target = 1;
	for (i = 0; 1; i++) {
		if (target < coin[i])
			break;
		target += coin[i];
	}
	printf("%d", target);
}