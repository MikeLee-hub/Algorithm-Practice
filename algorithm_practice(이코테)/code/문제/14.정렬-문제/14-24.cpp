// 14-24. ���׳� (p.360)

/*
	������ �߰� ���� ���׳��� ���ƾ� �Ÿ��� ������
	���� ��ġ�� sort�ؼ� �߰� �� ã��
	vector�� algorithm����� sort()�Լ� ���

	qsort�� �����ϸ� �� �����Ե� �����ҵ�
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> loc;
	int tmp_loc;
	int n;
	int i;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tmp_loc);
		loc.push_back(tmp_loc);
	}

	sort(loc.begin(), loc.end());

	if (n % 2 == 0)
		printf("%d", loc[n / 2 - 1]);
	else
		printf("%d", loc[n / 2]);
}