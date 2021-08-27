// 14-27. ���ĵ� �迭���� Ư�� ���� ���� ���ϱ� (p.367)

/*
	���� ��ü �迭�� ���� Ư�� ���� ��� ��� Ư������ Ž���ϰ� �Ǹ� �ð��� n�̵�.
	���� ���� ó�� index�� ������ index�� ���ؾ���.
	binary search�� �� �� �����Ͽ� ���
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