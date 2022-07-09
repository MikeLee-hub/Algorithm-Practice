// 10-2. 팀 결성 (p.298)

/*
	전형적인 서로소집합문제
*/

/*
예제입력:
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

예제출력:
NO
NO
YES
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int parent[100003];


int find_parent(int a) {
	if (parent[a] != a)
		parent[a] = find_parent(parent[a]);

	return parent[a];
}

int union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) {
		return 0;
	}
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
	return 1;
}

int main() {
	int a, b;
	int type;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &type, &a, &b);
		if (type) {
			if (find_parent(a) == find_parent(b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else {
			union_parent(a, b);
		}
	}

}