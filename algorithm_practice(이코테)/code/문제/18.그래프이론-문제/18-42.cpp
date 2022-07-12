// 18-42. ž�±� (p.395) (���� 10775��)

/*
	�׸��� �˰��� ���. ����Ⱑ ��� �ö����� ���� ���� ž�±��� ��ŷ.
	�̶� ���� �� ž�±��� ã������ ���μ����� �˰��� ���.
	��ŷ�Ϸ�� ����� �� ���� ž�±��� ���� ž�±��� union.
*/

/*
�����Է�:
3
3
0 1 0
1 0 1
0 1 0
1 2 3

�������:
YES
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g, p;
int parent[100005];

int find_parent(int a) {
	if (parent[a] != a)
		parent[a] = find_parent(parent[a]);

	return parent[a];
}

int docking(int a) {
	int b;
	a = find_parent(a);
	if (a == 0)
		return 0;
	b = find_parent(a - 1);

	parent[a] = b;
	return 1;
}

int main() {
	int gi;
	int i, ans;

	scanf("%d %d", &g, &p);

	for (i = 1; i <= g; i++)
		parent[i] = i;

	for (i = 0; i < p; i++) {
		scanf("%d", &gi);
		if (!docking(gi))
			break;
	}
	ans = i;
	for (i = i + 1; i < p; i++) {
		scanf("%d", &gi);
	}
	printf("%d\n", ans);

	return 0;
}