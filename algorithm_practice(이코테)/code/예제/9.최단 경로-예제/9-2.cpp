// 9-1. ������ �÷��̵� ���� �˰���

/*
	���� ������ ����Ͽ� �ִܰŸ��� ���ϴ� �˰���
	�ð����⵵ : O(n^3)
*/

/*
���� �Է�:
4
7
1 2 4
1 4 6
2 1 3
2 3 7
3 1 5
3 4 4
4 3 2

���� ���:
0 4 8 6
3 0 7 9
5 9 0 4
7 11 2 0
*/

#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int n, m;
int graph[1000][1000];

int main() {
	int a, b, c;
	scanf("%d %d", &n, &m); // node��&������
	
	// initial graph
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			graph[i][j] = INT_MAX;
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a-1][b-1] = c;
	}

	for (int mid = 0; mid < n; mid++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][mid] == INT_MAX || graph[mid][j] == INT_MAX)
					continue;
				c = graph[i][mid] + graph[mid][j];
				if (graph[i][j] > c)
					graph[i][j] = c;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	return 0;
}