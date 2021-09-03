// 16-31. 금광 (p.375)

/*
	현재위치까지의 값은
	왼쪽 위, 왼쪽, 왼쪽 아래 까지의 값 중 가장 큰 값 + 현재 위치값
	이 된다.

	이를 이용하여 dp사용한다.
*/

/*
예제입력:
2
3 4
1 3 3 2 2 1 4 1 0 6 4 7
4 4
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2

예제출력:
19
16
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int t;
int gold_list[1005][1005];
int n, m;

int get_max() {
	int i;
	int j;
	int before;
	int ans = 0;

	for (i = 1; i < m; i++) {
		before = max(gold_list[0][i-1], gold_list[1][i-1]);
		gold_list[0][i] += before;

		for (j = 1; j < n - 1; j++) {
			before = max(gold_list[j - 1][i-1], gold_list[j][i-1]);
			before = max(before, gold_list[j+1][i-1]);
			gold_list[j][i] += before;
		}

		before = max(gold_list[n - 1][i-1], gold_list[n- 2][i-1]);
		gold_list[n-1][i] += before;
	}


	for (i = 0; i < n; i++) {
		ans = max(ans, gold_list[i][m-1]);
	}
	return ans;
}

int main() {
	int i;
	int j, k;

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				scanf("%d", &gold_list[j][k]);
			}
		}
		printf("%d\n", get_max());
	}

}