// 16-34. 병사 배치하기 (p.380) (백준 18353번)

/*
	dp list는 n번째 병사까지만 보았을 때 남아있는 병사수를 저장한다.

	n번째 병사까지만 보았을 때 남아있는 병사 수 (dp[n]):
		0~n-1 중 전투력이 n번째보다 높은 병사들 중 가장 큰 dp값 + 1

	이를 이용하여 dp를 사용한다.
	시간 : n^2
*/

#include <stdio.h>

int n;
int sold_list[2005];
int dp[2005];

int main() {
	int i, j;
	int ans = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &sold_list[i]);
	dp[0] = 1;
	for (i = 1; i < n; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (sold_list[i] < sold_list[j]) {
				if (dp[j] >= dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d", n - ans);
}