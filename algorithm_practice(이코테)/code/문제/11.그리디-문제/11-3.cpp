// 11-3. ���ڿ� ������ (p.313)

/*
�׸����� ���缺:

*/

#include <stdio.h>

int main() {
	int n = 0;
	char c, before = 1;

	while (1) {
		scanf("%c", &c);
		if (c == '\0' || c == '\n')
			break;
		if (c != before) {
			before = c;
			n++;
		}
	}
	printf("%d\n", n / 2);
}