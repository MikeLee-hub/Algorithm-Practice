// 11-3. 문자열 뒤집기 (p.313)

/*
그리디의 정당성:

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