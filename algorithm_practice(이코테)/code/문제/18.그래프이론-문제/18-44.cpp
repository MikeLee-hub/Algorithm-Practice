// 18-43. 어두운길 (p.397) (백준 6497번)

/*
	전형적인 mst 구하기.
	크루스칼 or 프림 알고리즘 사용 가능.
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
#include <queue>
#include <vector>
#include <algorithm>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int n;
int ans;
int mode;
int parent[100003];

typedef struct {
	int xyx[3];
	int node_n;
}NODE;

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

bool comp(NODE a, NODE b) {
	return a.xyx[mode] < b.xyx[mode];
}

int main() {
	int a, b, c;
	int count;
	NODE new_node;
	vector<NODE> node_list;
	priority_queue<pair<int, pair<int, int>>> edge_list;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		new_node.node_n = i;
		scanf("%d %d %d", &new_node.xyx[0], &new_node.xyx[1], &new_node.xyx[2]);
		node_list.push_back(new_node);
		parent[i] = i;
	}

	for (mode = 0; mode < 3; mode++) {
		sort(node_list.begin(), node_list.end(), comp);
		for (int i = 0; i < n - 1; i++) {
			c = node_list[i + 1].xyx[mode] - node_list[i].xyx[mode];
			edge_list.push(make_pair(-1 * c, make_pair(node_list[i + 1].node_n, node_list[i].node_n)));
		}
	}
	
	ans = 0;
	count = 0;

	while (count < n - 1) {
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