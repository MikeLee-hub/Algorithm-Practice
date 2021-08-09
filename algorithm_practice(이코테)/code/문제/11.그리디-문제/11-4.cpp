// 11-4. 만들 수 없는 금액 (p.314)

/*
1~n번째 coin으로 k까지 만들 수 있으면,
1~n+1번째 coin으로는 value(n+1) ~ k + value(n+1)까지 만들 수 있다.

여기서 value(n+1)이 k+1보다 크면 k+1을 만들 방법이 없다.
*/
#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);//오름차순
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