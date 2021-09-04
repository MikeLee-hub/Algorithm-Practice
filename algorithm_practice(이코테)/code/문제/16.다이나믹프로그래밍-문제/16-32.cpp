// 16-32. �����ﰢ�� (p.376) (���� 1932��)

/*
	������ġ������ ����
	���� ��, ������ �� ������ �� �� ���� ū �� + ���� ��ġ��
	�� �ȴ�.

	�̸� �̿��Ͽ� dp����Ѵ�.
*/

#include <stdio.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int n;
int triangle[505][505];

int main() {
	int i, j;
	int tmp, ans;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}

	for (i = 1; i < n; i++) {
		triangle[i][0] += triangle[i - 1][0];
		for (j = 1; j < i; j++) {
			tmp = max(triangle[i - 1][j - 1], triangle[i - 1][j]);
			triangle[i][j] += tmp;
		}
		triangle[i][i] += triangle[i - 1][i-1];
	}

	ans = 0;
	for (i = 0; i < n; i++)
		ans = max(ans, triangle[n-1][i]);
	printf("%d", ans);
}