// 10-1-3. 위상정렬 (p.290)

/*
	
*/

/*
예제입력:
7 8
1 2
1 5
2 3
2 6
3 4
4 7
5 6
6 4

예제출력:
1 2 5 3 6 4 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int indegree[1000];
vector<int> edge[1000];
int v, e;

int main() {
	int a, b;
	queue<int> frontier;

	scanf("%d %d", &v, &e);
	memset(indegree, 0, sizeof(int) * v);

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0)
			frontier.push(i);
	}

	while (!frontier.empty()) {
		a = frontier.front();
		printf("%d ", a);
		frontier.pop();
		for (int i = 0; i < edge[a].size(); i++) {
			b = edge[a][i];
			indegree[b]--;
			if (indegree[b] == 0)
				frontier.push(b);
		}
		edge[a].clear();
	}

}