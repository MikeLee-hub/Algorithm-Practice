// 11-2. ���ϱ� Ȥ�� ���ϱ� (p.312)

/*
�׸����� ���缺:

a_n�� b_n���� ũ�� a_n+1 ���� b_n+1���� ũ��.
���� 1 <= n <= len(S) ������ ��� ���� n�� ���Ͽ� ���� ū a_n���� ã���� ���� ū ���� ã�� �� �ִ�.
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