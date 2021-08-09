// 12-7. 럭키 스트레이트(p.321)

/*
	string으로 처리
*/
#include <stdio.h>
#include <string.h>

int main() {
	char n[10];
	int len, half_len;
	int left, right;
	scanf("%s", n);

	len = strlen(n);
	half_len = len / 2;

	left = 0;
	for (int i = 0; i < half_len; i++)
		left += n[i] - '0';

	right = 0;
	for (int i = half_len; i < len; i++)
		right += n[i] - '0';

	if (left == right)
		printf("LUCKY\n");
	else
		printf("READY\n");
}