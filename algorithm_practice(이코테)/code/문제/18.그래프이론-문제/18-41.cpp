// 18-41. ���� ��ȹ (p.393) (���� 1976��)

/*
	���μ� ���� �˰����� �̿��Ͽ� ���� ������ ���� ���ϱ�
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

int n, m;
int parent[205];

int find_parent(int a) {
	if (parent[a] != a)
		parent[a] = find_parent(parent[a]);

	return parent[a];
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) {
		return;
	}
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	int n, np;
	int path;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &path);
			if (i < j)
				continue;
			if (path)
				union_parent(i, j);
		}
	}

	scanf("%d", &n);
	np = find_parent(n);
	for (int i = 1; i < m; i++) {
		scanf("%d", &n);
		if (np != find_parent(n)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}