// 8-5. 효율적인 화폐 구성 (p.226) (백준 2294번)

/*
	x원을 만들 수 있는 화폐 갯수:
		x - k원 화폐 개수 +1
	를 이용하여 dp 사용

	시간 : m * n

	책은 현재 화폐 단위를 기준으로, 본 코드는 현재 목표액을 기준으로 반복문을 구성하였는데
	비슷함. 둘다 시간 m * n
*/

/*
예제 입력:
2 15
2
3
예제 출력:
5

예제 입력:
3 4
3
5
7
예제 출력:
-1
*/
#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int dp_list[10005];
int coin_list[105];

int main() {
	int n, m;
	int i, j;
	int tmp;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		scanf("%d", &coin_list[i]);

	dp_list[0] = 0;
	for (i = 1; i <= m; i++) {
		dp_list[i] = 20000;
		for (j = 0; j < n; j++) {
			tmp = i - coin_list[j];
			if (tmp < 0)
				continue;
			dp_list[i] = min(dp_list[i], dp_list[tmp] + 1);
		}
	}
	if (dp_list[m] > 15000)
		dp_list[m] = -1;
	printf("%d", dp_list[m]);
	return 0;
}