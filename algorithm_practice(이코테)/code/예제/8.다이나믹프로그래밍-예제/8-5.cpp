// 8-5. ȿ������ ȭ�� ���� (p.226) (���� 2294��)

/*
	x���� ���� �� �ִ� ȭ�� ����:
		x - k�� ȭ�� ���� +1
	�� �̿��Ͽ� dp ���

	�ð� : m * n

	å�� ���� ȭ�� ������ ��������, �� �ڵ�� ���� ��ǥ���� �������� �ݺ����� �����Ͽ��µ�
	�����. �Ѵ� �ð� m * n
*/

/*
���� �Է�:
2 15
2
3
���� ���:
5

���� �Է�:
3 4
3
5
7
���� ���:
-1
*/
#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int dp_list[10005];
int coin_list[105];

int main() {
	int n, m;
	int i, j;
	int tmp;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		scanf("%d", &coin_list[i]);

	dp_list[0] = 0;
	for (i = 1; i <= m; i++) {
		dp_list[i] = 20000;
		for (j = 0; j < n; j++) {
			tmp = i - coin_list[j];
			if (tmp < 0)
				continue;
			dp_list[i] = min(dp_list[i], dp_list[tmp] + 1);
		}
	}
	if (dp_list[m] > 15000)
		dp_list[m] = -1;
	printf("%d", dp_list[m]);
	return 0;
}