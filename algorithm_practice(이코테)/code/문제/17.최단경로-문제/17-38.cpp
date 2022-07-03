// 16-38. ��Ȯ�� ���� (p.386) (���� 2458��)

/*
	�� �л��� �ϳ��� node
	�÷��̵���Ⱦ˰��� ���
	�� ��忡 ���� ��� ��尡 ȭ��ǥ�� �����ų� ������ ������ �� �� �ִ°�!!
*/
/*
���� �Է�:
6 6
1 5
3 4
4 2
4 6
5 2
5 4
*/
#include <stdio.h>
#include <string.h>

bool path[505][505];
int n, m;

int main() {
	int a, b;
	int ans = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		memset(path[i], 0, sizeof(bool) * (n + 2));

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		path[a][b] = true;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				if (path[i][mid] && path[mid][j])
					path[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		bool is_ok = true;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (path[i][j] || path[j][i]) 
				continue;
			is_ok = false;
			break;
		}
		if (is_ok)
			ans++;
	}
	printf("%d", ans);

	return 0;
}