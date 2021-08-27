// 14-27. 정렬된 배열에서 특정 수의 개수 구하기 (p.367)

/*
	만약 전체 배열이 전부 특정 수일 경우 모든 특정수를 탐색하게 되면 시간은 n이됨.
	따라서 제일 처음 index와 마지막 index만 구해야함.
	binary search를 두 번 구현하여 사용
*/

#include <stdio.h>

using namespace std;

int n, x;
int list[1000005];

int get_first() {
	int start, end, middle;
	start = 0;
	end = n - 1;
	while (start <= end) {
		middle = (start + end) / 2;
		if (list[middle] == x) {
			if (middle == 0)
				return middle;
			if (list[middle - 1] != x)
				return middle;
			end = middle - 1;
		}
		else if (list[middle] > x)
			end = middle - 1;
		else
			start = middle + 1;
	}
	return -1;
}

int get_last() {
	int start, end, middle;
	start = 0;
	end = n - 1;
	while (start <= end) {
		middle = (start + end) / 2;
		if (list[middle] == x) {
			if (middle == n-1)
				return middle;
			if (list[middle + 1] != x)
				return middle;
			start = middle + 1;
		}
		else if (list[middle] > x)
			end = middle - 1;
		else
			start = middle + 1;
	}
	return -1;
}

int main() {
	int i;
	int first, last;
	scanf("%d %d", &n, &x);

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	first = get_first();
	if (first == -1) {
		printf("-1");
		return 0;
	}

	last = get_last();

	printf("%d", last-first+1) ;

	return 0;
}