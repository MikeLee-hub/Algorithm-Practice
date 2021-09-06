// 16-34. ���� ��ġ�ϱ� (p.380) (���� 18353��)

/*
	dp list�� n��° ��������� ������ �� �����ִ� ������� �����Ѵ�.

	n��° ��������� ������ �� �����ִ� ���� �� (dp[n]):
		0~n-1 �� �������� n��°���� ���� ����� �� ���� ū dp�� + 1

	�̸� �̿��Ͽ� dp�� ����Ѵ�.
	�ð� : n^2
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