// 11-5. 볼링공 고르기 (p.315)
/*
	weight[i] = i무게를 가진 볼링공 수
	라고 하면

		무게 1로 조합할 수 있는 경우의 수 : n - weight[1]
		무게 1을 제외한 상태에서 무게 2로 조합할 수 있는 경우의 수 : n - weight[1] - weight[2]
			...
		무게 m-1로 조합할 수 있는 경우의 수 : weight[m] ( n-weight[1]- ... - weight[m-1]
	
	를 모두 더하면 전체 조합으 가지수가 된다.
*/
#include <stdio.h>
#include <string.h>

int weight[12];

int main() {
	int i;
	int n, m;
	int tmp;
	int ans;
	scanf("%d %d", &n, &m);
	memset(weight, 0, sizeof(int) * (m+1));

	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		weight[tmp] += 1;
	}

	ans = 0;

	for (i = 1; i <= m; i++) {
		n -= weight[i];
		ans += weight[i] * n;
	}

	printf("%d\n", ans);

}