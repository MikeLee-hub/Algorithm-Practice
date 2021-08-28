// 14-28. ������ ã�� (p.368)

/*
	index���� value������ ���� ��� : ���������� ��
	index���� value������ ū ��� : ���������� ��
	�� �̿��Ͽ� ���� Ž��
*/

/*
���� �Է�:
5
-15 -6 1 3 7

���:
3

���� �Է�:
7
-15 -4 2 8 9 13 15

���:
2

���� �Է�:
7
-15 -4 3 8 9 13 15

���:
-1
*/
#include <stdio.h>

int n;
int list[1000005];

int binary_search() {
	int start, end, middle;
	start = 0;
	end = n - 1;
	while (start <= end) {
		middle = (start + end) / 2;
		if (middle == list[middle])
			return middle;
		else if (middle > list[middle])
			start = middle + 1;
		else
			end = middle - 1;
	}
	return -1;
}

int main() {
	int i;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	printf("%d", binary_search());

	return 0;
}