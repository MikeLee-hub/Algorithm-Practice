// 14-26. ī�� �����ϱ� (p.363) (���� 1715��)

/*
	���� ���� �� ī�� ������ ���� ������ �ݺ��Ͽ� Ǯ �� �ִ�.
	priority queue ���
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