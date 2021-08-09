// 3-1. °Å½º¸§µ· (p.87)
#include <stdio.h>

int won[4] = { 500,100,50,10 };

int main() {
	int n;
	int ans = 0;

	scanf("%d", &n);

	for (int i = 0; i < 4; i++) {
		ans += n / won[i];
		n %= won[i];
	}
	printf("%d", ans);
}