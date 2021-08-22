// 14-26. 카드 정렬하기 (p.363) (백준 1715번)

/*
	제일 작은 두 카드 묶음을 묶는 동작을 반복하여 풀 수 있다.
	priority queue 사용
*/

#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> card;
	int n;
	int t;
	int i, j;
	int ans;
	int next;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		card.push(-t);
	}

	ans = 0;
	for (i = 0; i < n - 1; i++) {
		next = card.top();
		card.pop();
		next += card.top();
		card.pop();
		ans -= next;
		card.push(next);
	}
	printf("%d", ans);
	return 0;
}