// 16-36. �����Ÿ� (p.382)

/*

	���̵� �ֻ�
	���ش� �Ǵµ� �� ����Ѱ� ���߿� �ٽ� Ǯ �� ������ �� �𸣰���...
*/

#include <stdio.h>
#include <string.h>

int dp[5005][5005];
char a[5005];
char b[5005];

int get_min(int x, int y, int z) {
	if (x <= y) {
		if (x <= z)
			return x;
	}
	else {
		if (y <= z)
			return y;
	}
	return z;
}

int main() {
	int i, j;
	int len_a, len_b;
	scanf("%s", a);
	scanf("%s", b);
	len_a = strlen(a);
	len_b = strlen(b);

	for (i = 0; i<=len_a; i++) {
		dp[0][i] = i;
	}

	for (i = 0; i <= len_b; i++) {
		dp[i][0] = i;
	}

	for (i = 0; i < len_a; i++) {
		for (j = 0; j < len_b; j++) {
			if (a[i] == b[j])
				dp[j+1][i+1] = dp[j][i];
			else
				dp[j + 1][i + 1] = 1 + get_min(dp[j][i], dp[j + 1][i], dp[j][i + 1]);
		}
	}
	printf("%d", dp[len_b][len_a]);
}