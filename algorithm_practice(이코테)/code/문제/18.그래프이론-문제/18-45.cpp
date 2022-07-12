// 18-45. 최종순위 (p.398) (백준 3665번)

/*
	위상정렬.
	indegree가 0인 친구가 두 개 이상이면 순위 모름.
	indegree가 0인 친구가 없으면 순위 만들 수 없음.(얽히고 얽히는 관계)
	indegree가 0인 친구가 하나씩 차례차례 나오면 깔끔하게 순위가 나옴
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
#include <vector>

using namespace std;

int indegree[502];
bool edge[502][502];
int n, inverse_n;

int main() {
	int t;
	int a, b;
	int tmp;
	queue<int> frontier;
	vector<int> ans;
	scanf("%d", &t);

	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		memset(indegree, 0, sizeof(int) * (n+1));
		for (int i = 1; i <= n; i++) {
			memset(edge[i], false, sizeof(bool) * (n + 1));
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			for (b = 1; b <= n; b++) {
				if (a == b)
					continue;
				if (edge[b][a])
					continue;
				edge[a][b] = true;
				indegree[b]++;
			}
		}
		
		scanf("%d", &inverse_n);
		for (int i = 0; i < inverse_n; i++) {
			scanf("%d %d", &a, &b);
			if (edge[a][b]) {
				tmp = a;
				a = b;
				b = tmp;
			}
			edge[a][b] = true;
			edge[b][a] = false;
			indegree[b]++;
			indegree[a]--;
		}

		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0)
				frontier.push(i);
		}

		if (frontier.size() > 1) {
			printf("?\n");
			while (!frontier.empty())
				frontier.pop();
			continue;
		}

		while (!frontier.empty()) {
			a = frontier.front();
			ans.push_back(a);
			frontier.pop();
			for (b = 1; b <= n; b++) {
				if (!edge[a][b])
					continue;
				indegree[b]--;
				if (indegree[b] == 0)
					frontier.push(b);
			}
			if (frontier.size() > 1) {
				printf("?\n");
				break;
			}
		}
		if (!frontier.empty()) {
			while (!frontier.empty())
				frontier.pop();
		}
		else if (ans.size() == n) {
			for (int i = 0; i < n; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
		else {
			printf("IMPOSSIBLE\n");
		}
		ans.clear();
	}
}