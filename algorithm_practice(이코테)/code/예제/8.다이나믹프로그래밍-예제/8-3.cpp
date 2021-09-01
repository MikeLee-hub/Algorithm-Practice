// 8-3. 개미 전사 (p.220)

/*
	1 ~ x번째 까지의 최대 값 - x-1값 그대로
							  or x-2값에 본인을 더하기
						
	이게 가능한 이유 : x-3보다 무조건 x-1이 크다는게 보장됨

	따라서 첫 번째 원소부터 위의 조건을 이용하여 구해 나가기
*/

/*
예제 입력:
4
1 3 1 5

예제 출력:
8
*/
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int dp_list[105];
int k[105];

int main() {
	int n;
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
	}

	dp_list[0] = 0;
	dp_list[1] = k[1];
	for (i = 2; i <= n; i++)
		dp_list[i] = max(dp_list[i - 1], dp_list[i - 2] + k[i]);

	printf("%d", dp_list[n]);
}