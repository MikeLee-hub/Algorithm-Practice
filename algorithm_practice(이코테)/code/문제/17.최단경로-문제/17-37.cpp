// 16-36. �÷��̵� (p.385) (���� 11404��)

/*
	�÷��̵� ���� �˰��� ��� �⺻����
*/

#include <stdio.h>
#include <string.h>

int path[105][105];
int n, m;

int main() {
	int a, b, c;
	int new_c;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		memset(path[i], 0, sizeof(int) * (n + 2));

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if(!path[a][b] || path[a][b] >c)
			path[a][b] = c;
	}


	for (int mid = 1; mid <= n; mid++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				if (!path[i][mid] || !path[mid][j])
					continue;

				new_c = path[i][mid] + path[mid][j];
				if (!path[i][j] || new_c < path[i][j])
					path[i][j] = new_c;
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", path[i][j]);
		printf("\n");
	}
}