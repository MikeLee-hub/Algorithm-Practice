// 11-1. 모험가길드 (p.311)

/*
그리디의 정당성:

각 파티는 최소 인원으로 구성되야 되고,
무조건 공포도가 작은 사람들로 구성해야 더 적은 사람으로 파티를 짤 수 있음.
공포도가 작은 사람들부터 계산하여 최소 인원으로 매칭
*/

#include <stdio.h>
#include <stdlib.h>

int gongpo[100005];

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);//오름차순
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