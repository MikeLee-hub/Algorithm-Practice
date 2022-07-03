// 8-2. 1�� ����� (p.217) (���� 1463��)

/*
	x�� ����Ƚ���� x/5�� ����Ƚ�� + 1 
				   or x/3�� ����Ƚ�� + 1 
				   or x/2�� ����Ƚ�� + 1
				   or x-1�� ����Ƚ�� + 1
	�� �� �� �ۿ� ����.
	�̸� �̿��Ͽ� dynamic programming�� ����Ͽ� 1���� x������ ��� ����Ƚ���� ���Ѵ�.
	�ð� : x
*/

/*
���� �Է�:
26

���� ���:
3
*/
#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int dp_list[30005];

int main() {
	int x;
	int i;
	scanf("%d", &x);

	dp_list[1] = 0;
	dp_list[2] = 1;

	for (i = 3; i <= x; i++) {
		dp_list[i] = dp_list[i - 1] + 1;
		if (i % 5 == 0)
			dp_list[i] = min(dp_list[i], dp_list[i / 5] + 1);
		if (i % 3 == 0)
			dp_list[i] = min(dp_list[i], dp_list[i / 3] + 1);
		if (i % 2 == 0)
			dp_list[i] = min(dp_list[i], dp_list[i / 2] + 1);
	}
	printf("%d", dp_list[x]);
}