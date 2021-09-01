// 8-4. 바닥 공사 (p.223)

/*
	그려보면 

	x번째 : x-1번째 + (x-2번째 * 2)

	임을 알 수 있다

	따라서 dp 사용
*/

/*
예제 입력:
3

예제 출력:
5
*/
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int dp_list[1005];

int main() {
	int n;
	int i;
	scanf("%d", &n);

	dp_list[1] = 1;
	dp_list[2] = 3;

	for (i = 3; i <= n; i++) {
		dp_list[i] = dp_list[i - 2] * 2 + dp_list[i - 1];
		dp_list[i] %= 796796;
	}
	printf("%d", dp_list[n]);

}