// 7-2. 부품 찾기 (p.197)

/*
	n list에 m list의 원소를 탐색하는 문제
	sequence search를 하게 되면 n * m의 시간복잡도를 가짐.
	정렬 후 binary search를 하게 되면 n * log_n + m * log_n 이 된다.
	따라서 binary search가 더 유리하다.

	but n의 범위가 정해져 있으므로, count sort와 비슷한 느낌으로 구현하면 n + m 구현 가능
*/

/*
예제 입력:
5
8 3 7 9 2
3
5 7 9

예제 출력:
no yes yes
*/
#include <stdio.h>
#include <stdlib.h>

int n_list[1000005];
int n, m;

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

int binary_search_recurse(int n, int start, int end) {
	int middle;
	if (start > end)
		return -1;
	middle = (start + end) / 2;
	if (n_list[middle] > n)
		return binary_search_recurse(n, start, middle - 1);
	else if (n_list[middle] < n)
		return binary_search_recurse(n, middle + 1, end);
	else
		return middle;
}

int main() {
	int i;
	int lookingfor;
	int is_exist;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &n_list[i]);
	
	qsort(n_list, n, sizeof(int), comp);
	
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &lookingfor);
		is_exist = binary_search_recurse(lookingfor, 0, n - 1);
		if (is_exist == -1)
			printf("no ");
		else
			printf("yes ");
	}
	return 0;
}