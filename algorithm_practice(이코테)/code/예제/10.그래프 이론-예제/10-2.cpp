// 10-1-2. 크루스칼 알고리즘 (p.268)

/*
	크루스칼 알고리즘으로 mst cost 구하기
*/

/*
예제입력:
7 9
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25


예제출력:
159
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

int v, e;
int ans;
int parent[10003];

using namespace std;

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
	int a, b, c;
	int count;
	priority_queue<pair<int, pair<int, int>>> edge_list;

	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge_list.push(make_pair(-1 * c, make_pair(a, b)));
	}

	ans = 0;
	count = 0;

	while (count < v-1) {
		c = -1 * edge_list.top().first;
		a = edge_list.top().second.first;
		b = edge_list.top().second.second;
		edge_list.pop();
		if (union_parent(a, b)) {
			ans += c;
			count++;
		}
	}

	printf("%d", ans);

	return 0;
}