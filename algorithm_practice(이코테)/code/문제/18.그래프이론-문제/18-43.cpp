// 18-43. 어두운길 (p.397) (백준 6497번)

/*
	전형적인 mst 구하기.
	크루스칼 or 프림 알고리즘 사용 가능. 크루스칼 사용.
*/

/*
예제입력:
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0

예제출력:
51
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

int v, e;
int ans;
int parent[200005];

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
	while (true) {
		scanf("%d %d", &v, &e);
		if (v == 0)
			return 0;
		for (int i = 0; i < v; i++)
			parent[i] = i;

		ans = 0;
		for (int i = 0; i < e; i++) {
			scanf("%d %d %d", &a, &b, &c);
			edge_list.push(make_pair(-1 * c, make_pair(a, b)));
			ans += c;
		}

		count = 0;

		while (!edge_list.empty()) {
			c = -1 * edge_list.top().first;
			a = edge_list.top().second.first;
			b = edge_list.top().second.second;
			edge_list.pop();
			if (union_parent(a, b)) {
				ans -= c;
				count++;
			}
		}

		printf("%d\n", ans);
	}
}