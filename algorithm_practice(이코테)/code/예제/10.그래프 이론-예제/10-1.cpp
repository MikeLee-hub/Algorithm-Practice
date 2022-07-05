// 10-1-1. ���μ� ���� �˰��� (p.268)

/*
���μ� ���� �˰����� �̿��� cycle �Ǻ�
*/

/*
�����Է�:
3 3
1 2
1 3
2 3

�������:
O
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v, e;
int parent[10003];

int find_parent(int a) {
	if (parent[a] != a)
		parent[a] = find_parent(parent[a]);

	return parent[a];
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) {
		printf("O");
		exit(0);
	}
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	int a, b;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		union_parent(a, b);
	}
	printf("X");

	return 0;
}