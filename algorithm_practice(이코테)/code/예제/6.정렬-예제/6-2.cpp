// 6-2. ������ �Ʒ��� (p.178)

/*
	0~100000 �������� �ڿ����� ����
	
	(n * \log_{2}{n} = 500 * 9 = 4500)
	(n+k = 500 + 100000 = 100500)
	(n^{2} = 500*500 = 250000)

	�̹Ƿ� n * \log_{2}{n}�� qsort�� ���
*/
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> list;
void quik_sort(int start, int end) {
	int i, j;
	int pivot;
	int tmp;
	if (start > end)
		return;

	pivot = list[start];

	i = start + 1;
	j = end;
	while (i <= j) {
		for (; i <= end; i++) {
			if (pivot >= list[i])
				break;
		}
		for (; j > start; j--) {
			if (pivot < list[j])
				break;
		}
		if (i < j) {
			tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
		}
		else {
			list[start] = list[j];
			list[j] = pivot;
		}
	}
	quik_sort(start, j - 1);
	quik_sort(j + 1, end);

	return;
}

int main() {
	int n;
	int i, j;
	int t;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		list.push_back(t);
	}
	quik_sort(0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	return 0;
}