// 11-2. 곱하기 혹은 더하기 (p.312)

/*
그리디의 정당성:

a_n이 b_n보다 크면 a_n+1 또한 b_n+1보다 크다.
따라서 1 <= n <= len(S) 범위의 모든 정수 n에 대하여 가장 큰 a_n값을 찾으면 가장 큰 값을 찾을 수 있다.
*/

#include <stdio.h>

char s[22];

int main() {
	int ans = 0;
	int n = 1;
	int add, mul;
	scanf("%s", &s);
	ans = s[0] - '0';
	while (1) {
		if (s[n] == '\n' || s[n] == '\0')
			break;
		add = ans + s[n] - '0';
		mul = ans * (s[n] - '0');
		if (add > mul)
			ans = add;
		else
			ans = mul;
		n++;
	}
	printf("%d\n", ans);
	return 0;
}