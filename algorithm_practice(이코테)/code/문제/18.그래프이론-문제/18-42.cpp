// 18-42. 탑승구 (p.395) (백준 10775번)

/*
	그리디 알고리즘 사용. 비행기가 들어 올때마다 가장 뒤의 탑승구에 도킹.
	이때 가장 뒤 탑승구를 찾기위해 서로소집합 알고리즘 사용.
	도킹완료시 사용할 수 없는 탑승구는 왼쪽 탑승구와 union.
*/

/*
예제입력:
3
3
0 1 0
1 0 1
0 1 0
1 2 3

예제출력:
YES
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g, p;
int parent[100005];

int find_parent(int a) {
	if (parent[a] != a)
		parent[a] = find_parent(parent[a]);

	return parent[a];
}

int docking(int a) {
	int b;
	a = find_parent(a);
	if (a == 0)
		return 0;
	b = find_parent(a - 1);

	parent[a] = b;
	return 1;
}

int main() {
	int gi;
	int i, ans;

	scanf("%d %d", &g, &p);

	for (i = 1; i <= g; i++)
		parent[i] = i;

	for (i = 0; i < p; i++) {
		scanf("%d", &gi);
		if (!docking(gi))
			break;
	}
	ans = i;
	for (i = i + 1; i < p; i++) {
		scanf("%d", &gi);
	}
	printf("%d\n", ans);

	return 0;
}