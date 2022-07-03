// 8-2. 1로 만들기 (p.217) (백준 1463번)

/*
	x의 연산횟수는 x/5의 연산횟수 + 1 
				   or x/3의 연산횟수 + 1 
				   or x/2의 연산횟수 + 1
				   or x-1의 연산횟수 + 1
	이 될 수 밖에 없음.
	이를 이용하여 dynamic programming을 사용하여 1부터 x까지의 모든 연산횟수를 구한다.
	시간 : x
*/

/*
예제 입력:
26

예제 출력:
3
*/
#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int dp_list[30005];

int main() {
	int x;
	int i;
	scanf("%d", &x);

	dp_list[1] = 0;
	dp_list[2] = 1;

	for (i = 3; i <= x; i++) {
		dp_list[i] = dp_list[i - 1] + 1;
		if (i % 5 == 0)
			dp_list[i] = min(dp_list[i], dp_list[i / 5] + 1);
		if (i % 3 == 0)
			dp_list[i] = min(dp_list[i], dp_list[i / 3] + 1);
		if (i % 2 == 0)
			dp_list[i] = min(dp_list[i], dp_list[i / 2] + 1);
	}
	printf("%d", dp_list[x]);
}