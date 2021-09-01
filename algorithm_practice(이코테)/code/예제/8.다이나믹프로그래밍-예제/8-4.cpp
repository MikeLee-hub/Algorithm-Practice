// 8-4. �ٴ� ���� (p.223)

/*
	�׷����� 

	x��° : x-1��° + (x-2��° * 2)

	���� �� �� �ִ�

	���� dp ���
*/

/*
���� �Է�:
3

���� ���:
5
*/
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int dp_list[1005];

int main() {
	int n;
	int i;
	scanf("%d", &n);

	dp_list[1] = 1;
	dp_list[2] = 3;

	for (i = 3; i <= n; i++) {
		dp_list[i] = dp_list[i - 2] * 2 + dp_list[i - 1];
		dp_list[i] %= 796796;
	}
	printf("%d", dp_list[n]);

}