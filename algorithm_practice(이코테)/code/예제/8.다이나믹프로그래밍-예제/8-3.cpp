// 8-3. ���� ���� (p.220)

/*
	1 ~ x��° ������ �ִ� �� - x-1�� �״��
							  or x-2���� ������ ���ϱ�
						
	�̰� ������ ���� : x-3���� ������ x-1�� ũ�ٴ°� �����

	���� ù ��° ���Һ��� ���� ������ �̿��Ͽ� ���� ������
*/

/*
���� �Է�:
4
1 3 1 5

���� ���:
8
*/
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int dp_list[105];
int k[105];

int main() {
	int n;
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
	}

	dp_list[0] = 0;
	dp_list[1] = k[1];
	for (i = 2; i <= n; i++)
		dp_list[i] = max(dp_list[i - 1], dp_list[i - 2] + k[i]);

	printf("%d", dp_list[n]);
}