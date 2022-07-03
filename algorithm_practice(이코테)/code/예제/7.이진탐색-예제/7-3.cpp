// 7-3. 떡볶이 떡 만들기 (p.201) (백준 2805번)

/*
	n이 m보다 많이 많이 작으므로 m에 대한 시간복잡도가 작아야함
	m을 binary search로 찾기
	시간 : n * log_m
*/

/*
예제 입력:
4 6
19 15 10 17

예제 출력:
15
*/
#include <stdio.h>
#include <stdlib.h>

int len[1000005];
int n, m;

int comp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

long long get_cut_len(int m) {
	int i;
	long long hab = 0;
	for (i = 0; i < n; i++) {
		if (len[i] > m)
			hab = hab + ((long long)len[i]) - m;
	}
	return hab;
}

int binary_search(int end) {
	int start = 0;
	int middle;
	long long tmp_len;

	while (start<=end) {
		middle = (start + end) / 2;
		tmp_len = get_cut_len(middle);
		if (tmp_len == m)
			return middle;
		else if (tmp_len > m)
			start = middle + 1;
		else
			end = middle - 1;
	}
	return end;
}

int main() {
	int i;
	int max = 0;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		scanf("%d", &len[i]);
		if (max < len[i])
			max = len[i];
	}

	printf("%d", binary_search(max));
}