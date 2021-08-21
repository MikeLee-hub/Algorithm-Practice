// 14-24. 안테나 (p.360)

/*
	무조건 중간 집에 안테나를 놓아야 거리가 같아짐
	집의 위치를 sort해서 중간 집 찾기
	vector와 algorithm헤더의 sort()함수 사용

	qsort를 응용하면 더 빠르게도 가능할듯
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