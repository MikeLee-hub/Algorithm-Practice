// 10-4. 커리큘럼 (p.303)

/*
예제입력:
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

예제출력:
10
20
14
18
17
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int time[502];
int indegree[502];
vector<int> edge[502];
int v;

int main() {
	int a, b, e;
	queue<int> frontier;

	scanf("%d", &v);

	for (int i = 1; i <= v; i++) {
		scanf("%d", &time[i]);
		indegree[i] = 0;
		while (true) {
			scanf("%d", &e);
			if (e < 0)
				break;
			edge[e].push_back(i);
			indegree[i]++;
		}
		if (indegree[i] == 0) {
			frontier.push(i);
		}
	}


	while (!frontier.empty()) {
		a = frontier.front();
		frontier.pop();
		for (int i = 0; i < edge[a].size(); i++) {
			b = edge[a][i];
			indegree[b]--;
			if (indegree[b] == 0) {
				frontier.push(b);
				time[b] += time[a];
			}
		}
		edge[a].clear();
	}
	for (int i = 1; i <= v; i++)
		printf("%d\n", time[i]);
}