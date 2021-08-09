// 11-5. ������ ���� (p.315)
/*
	weight[i] = i���Ը� ���� ������ ��
	��� �ϸ�

		���� 1�� ������ �� �ִ� ����� �� : n - weight[1]
		���� 1�� ������ ���¿��� ���� 2�� ������ �� �ִ� ����� �� : n - weight[1] - weight[2]
			...
		���� m-1�� ������ �� �ִ� ����� �� : weight[m] ( n-weight[1]- ... - weight[m-1]
	
	�� ��� ���ϸ� ��ü ������ �������� �ȴ�.
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