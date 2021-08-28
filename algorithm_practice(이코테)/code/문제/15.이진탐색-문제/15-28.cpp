// 14-28. 고정점 찾기 (p.368)

/*
	index값이 value값보다 작은 경우 : 고정점보다 뒤
	index값이 value값보다 큰 경우 : 고정점보다 앞
	을 이용하여 이진 탐색
*/

/*
예제 입력:
5
-15 -6 1 3 7

출력:
3

예제 입력:
7
-15 -4 2 8 9 13 15

출력:
2

예제 입력:
7
-15 -4 3 8 9 13 15

출력:
-1
*/
#include <stdio.h>

int n;
int list[1000005];

int binary_search() {
	int start, end, middle;
	start = 0;
	end = n - 1;
	while (start <= end) {
		middle = (start + end) / 2;
		if (middle == list[middle])
			return middle;
		else if (middle > list[middle])
			start = middle + 1;
		else
			end = middle - 1;
	}
	return -1;
}

int main() {
	int i;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	printf("%d", binary_search());

	return 0;
}