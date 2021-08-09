// 3-4. 1이 될 때까지(p.99)
#include <stdio.h>

int main() {
	int n, k;
	int cnt;
	
	scanf("%d %d", &n, &k);
	/*
	for (cnt = 0; n > 1; cnt++) {
		if (n % k == 0)
			n /= k;
		else
			n -= 1;
	}
	*/
	for (cnt = 0; n >= k; cnt++) {
		cnt += (n - (n / k) * k);
		n = n / k;
	}
	cnt += n - 1;
	printf("%d\n", cnt);
}