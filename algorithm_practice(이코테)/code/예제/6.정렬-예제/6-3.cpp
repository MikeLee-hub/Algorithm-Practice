// 6-3. ������ ���� ������ �л� ����ϱ� (p.178)

/*
	�л������� int�� string�� pair�� ���ͷ� ���� ��
	c++ algorithm ����� sort ���
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n;
	int i;
	int score;
	char name[105];
	vector<pair<int, string>>  a;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s%d", name, &score);
		a.push_back({ score, name });
	}
	sort(a.begin(), a.end());
	for (i = 0; i < n; i++)
		cout << a[i].second << " ";
}