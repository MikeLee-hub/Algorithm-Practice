// 16-33. ��� (p.377) (���� 14501��)

/*
	�ڿ������� ���
	i��° ��¥�� �ϰԵȴٸ� i+pi������ ���� ���ϱ� ��� ����
	���ϰ� �ȴٸ� i+1����
	�� �̿��Ͽ� dp ���
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