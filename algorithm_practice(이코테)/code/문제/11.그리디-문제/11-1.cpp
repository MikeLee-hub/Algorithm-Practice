// 11-1. ���谡��� (p.311)

/*
�׸����� ���缺:

�� ��Ƽ�� �ּ� �ο����� �����Ǿ� �ǰ�,
������ �������� ���� ������ �����ؾ� �� ���� ������� ��Ƽ�� © �� ����.
�������� ���� �������� ����Ͽ� �ּ� �ο����� ��Ī
*/

#include <stdio.h>
#include <stdlib.h>

int gongpo[100005];

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);//��������
}

int main() {
	int n;
	int i;
	int j;
	int max_g;
	int ans;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &gongpo[i]);

	qsort(gongpo, n, sizeof(int), comp);

	i = 0;
	ans = 0;
	while (i < n) {
		max_g = gongpo[i];
		j = 1;
		while (j<max_g) {
			i++;
			if (i >= n) {
				printf("%d\n", ans);
				return 0;
			}
			max_g = gongpo[i];
			j++;
		}
		ans++;
		i++;
	}
	printf("%d\n", ans);
	return 0;
}