// 7-1. 기본 이진 탐색 코드 (p.188)

/*
	이진 탐색을 재귀와 반복문으로 실행하는 함수 구현
*/

/*
아래 코드 실행 결과:

binary search recurse
		7 in index 3
binary search repeat
		7 in index 3

binary search recurse
		6 : No such element
binary search repeat
		6 : No such element
*/
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int binary_search_recurse(int n, vector<int> list, int start, int end) {
	int middle;
	if (start > end)
		return -1;
	middle = (start + end) / 2;
	if (list[middle] > n)
		return binary_search_recurse(n, list, start, middle - 1);
	else if (list[middle] < n)
		return binary_search_recurse(n, list, middle + 1, end);
	else
		return middle;
}

int binary_search_repeat(int n, vector<int> list) {
	int start = 0;
	int end = list.size()-1;
	int middle;

	while (start <= end) {
		middle = (start + end) / 2;
		if (list[middle] == n)
			return middle;
		else if (list[middle] > n)
			end = middle - 1;
		else
			start = middle + 1;
	}
	return -1;
}

int main() {
	vector<int> list = { 1,3,5,7,9,11,13,15,17,19 };
	int tmp;

	tmp = binary_search_recurse(7, list, 0, list.size()-1);
	if(tmp == -1)
		printf("binary search recurse\n\t7 : No such element\n");
	else
		printf("binary search recurse\n\t7 in index %d\n", tmp);

	tmp = binary_search_repeat(7, list);
	if (tmp == -1)
		printf("binary search repeat\n\t7 : No such element\n", 7);
	else
		printf("binary search repeat\n\t7 in index %d\n", tmp);
	printf("\n");
	tmp = binary_search_recurse(6, list, 0, list.size()-1);
	if (tmp == -1)
		printf("binary search recurse\n\t6 : No such element\n");
	else
		printf("binary search recurse\n\t6 in index %d\n", tmp);

	tmp = binary_search_repeat(6, list);
	if (tmp == -1)
		printf("binary search repeat\n\t6 : No such element\n");
	else
		printf("binary search repeat\n\t6 in index %d\n", tmp);

}