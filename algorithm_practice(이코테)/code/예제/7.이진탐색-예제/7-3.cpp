// 7-3. ������ �� ����� (p.201) (���� 2805��)

/*
	n�� m���� ���� ���� �����Ƿ� m�� ���� �ð����⵵�� �۾ƾ���
	m�� binary search�� ã��
	�ð� : n * log_m
*/

/*
���� �Է�:
4 6
19 15 10 17

���� ���:
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