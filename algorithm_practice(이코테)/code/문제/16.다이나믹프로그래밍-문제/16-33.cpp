// 16-33. 퇴사 (p.377) (백준 14501번)

/*
	뒤에서부터 계산
	i번째 날짜를 하게된다면 i+pi까지의 페이 더하기 요번 페이
	안하게 된다면 i+1페이
	를 이용하여 dp 계산
*/

#include <stdio.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int n;
int t[20];
int p[20];
int dp[20];

int main() {
	int i, j;
	int tmp;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}

	dp[i] = 0;

	for (i = n; i > 0; i--) {
		if (i + t[i] - 1 <= n) {
			dp[i] =max(dp[i + t[i]] + p[i], dp[i+1]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}
	printf("%d", dp[1]);
}