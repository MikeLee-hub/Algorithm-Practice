// 6-3. 성적이 낮은 순서로 학생 출력하기 (p.178)

/*
	학생정보를 int와 string의 pair의 벡터로 저장 후
	c++ algorithm 헤더의 sort 사용
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