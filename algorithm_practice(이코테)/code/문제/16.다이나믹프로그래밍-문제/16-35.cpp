// 16-35. ������ �� (p.381)

/*
	1�� 2,3,5�踦 �ϸ� ������ ���� �����ȴ�.
	�̷��� ������ ������ ���� �ٽ� 2,3,5�踦 �ϸ� ������ ���� �����ȴ�.
	�̸� ��������� �ݺ��ϸ� ������ ���� ��� ���� �� �ִ�. (D.P)

	But, �̷��� ���ϰԵǸ� ũ����� �ƴϴ�.  (2^2 < 5)
	���� 2���, 3���, 5����� ������ ������ش�.
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