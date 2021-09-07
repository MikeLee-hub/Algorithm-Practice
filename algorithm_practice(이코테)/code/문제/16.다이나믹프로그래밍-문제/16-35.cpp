// 16-35. 못생긴 수 (p.381)

/*
	1에 2,3,5배를 하면 못생긴 수가 생성된다.
	이렇게 생성된 못생긴 수에 다시 2,3,5배를 하면 못생긴 수가 생성된다.
	이를 재귀적으로 반복하면 못생긴 수를 모두 구할 수 있다. (D.P)

	But, 이렇게 구하게되면 크기순이 아니다.  (2^2 < 5)
	따라서 2배수, 3배수, 5배수를 나누어 계산해준다.
*/

#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> dp;

int get_min(int x, int y, int z) {
	if (x <= y) {
		if (x <= z)
			return x;
	}
	else {
		if (y <= z)
			return y;
	}
	return z;
}

int main() {
	int i;
	int next_num_2, idx_2;
	int next_num_3, idx_3;
	int next_num_5, idx_5;

	scanf("%d", &n);
	
	dp.push_back(1);
	next_num_2 = 2;
	next_num_3 = 3;
	next_num_5 = 5;
	idx_2 = idx_3 = idx_5 = 1;

	for (i = 1; i < n; i++) {
		dp.push_back(get_min(next_num_2, next_num_3, next_num_5));
		if (dp[i] == next_num_2)
			next_num_2 = 2 * dp[idx_2++];
		if (dp[i] == next_num_3)
			next_num_3 = 3 * dp[idx_3++];
		if (dp[i] == next_num_5)
			next_num_5 = 5 * dp[idx_5++];
	}
	printf("%d", dp[n - 1]);
}