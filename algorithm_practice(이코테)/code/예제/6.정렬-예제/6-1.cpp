// 6-1. 기본 정렬 알고리즘 (p.156)

/*
	1. selection sort
	2. insertion sort
	3. quik sort
	4. count sort

	를 내림차순 정렬로 구현하는 함수
*/
#define MAX_ELEMENT 10

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

void print_vector(vector<int> list) {
	int n = list.size();
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return;
}

// selection sort
vector<int> selection_sort(vector<int> list) {
	int n = list.size();
	int i, j;
	int min_idx;
	int tmp;

	for (i = 0; i < n; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (list[min_idx] > list[j])
				min_idx = j;
		}
		tmp = list[i];
		list[i] = list[min_idx];
		list[min_idx] = tmp;
	}
	return list;
}

// insertion sort
vector<int> insertion_sort(vector<int> list) {
	int n = list.size();
	int i, j;
	int tmp;

	for (i = 1; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (list[j] < list[j - 1]) {
				tmp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = tmp;
			}
		}
	}
	return list;

}

// quik sort에서 사용하는 재귀함수
void quik_sort_recurse(vector<int>* list, int start, int end) {
	int i, j;
	int pivot;
	int tmp;
	if (start > end)
		return;
	
	pivot = (*list)[start];

	i = start+1;
	j = end;
	while (i <= j) {
		for (; i <= end; i++) {
			if (pivot <= (*list)[i])
				break;
		}
		for (; j > start; j--) {
			if (pivot > (*list)[j])
				break;
		}
		if (i < j) {
			tmp = (*list)[i];
			(*list)[i] = (*list)[j];
			(*list)[j] = tmp;
		}
		else {
			(*list)[start] = (*list)[j];
			(*list)[j] = pivot;
		}
	}
	quik_sort_recurse(list, start, j - 1);
	quik_sort_recurse(list, j+1, end);

	return;
}

// quik sort (pivot : 첫 번째 원소)
vector<int> quik_sort(vector<int> list) {
	quik_sort_recurse(&list, 0, list.size() - 1);
	return list;
}

// count sort
vector<int> count_sort(vector<int> list) {
	int i, j;
	int n = list.size();
	int num[MAX_ELEMENT];
	memset(num, 0, sizeof(int) * MAX_ELEMENT);
	for (i = 0; i < n; i++)
		num[list[i]]++;
	list.clear();
	for (i = 0; i < MAX_ELEMENT; i++) {
		for (j = 0; j < num[i]; j++)
			list.push_back(i);
	}

	return list;

}

int main() {
	vector<int> list = { 7,5,9,0,3,1,6,2,4,8 };

	print_vector(selection_sort(list));
	print_vector(insertion_sort(list));
	print_vector(quik_sort(list));
	print_vector(count_sort(list));
}