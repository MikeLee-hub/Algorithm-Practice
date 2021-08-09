// 12-13. 치킨배달(p.332)

/*
	총 집의 수와 그 좌표들
	총 치킨집의 수와 그 좌표들을 저장한다.
	치킨집 중 m개를 뽑는다. (chicken_n C m)
	치킨거리를 모두 구하고 최솟값을 저장한다.
*/
#include <stdio.h>
#include <stdlib.h>

int n, m;

int chicken_n;
int chicken_x[15];
int chicken_y[15];

int checking_chicken_x[15];
int checking_chicken_y[15];

int house_n;
int house_x[105];
int house_y[105];

int get_dist() {
	int total = 0;
	int single;
	int tmp_ans;
	int i, j;
	for (i = 0; i < house_n; i++) {
		single = 99999999;
		for (j = 0; j < m; j++) {
			tmp_ans = abs(checking_chicken_x[j] - house_x[i]) + abs(checking_chicken_y[j] - house_y[i]);
			if (tmp_ans < single)
				single = tmp_ans;
		}
		total += single;
	}
	return total;
}

int checking(int c, int d) {
	int i;
	int ans = 999999999;
	int tmp_ans;

	if (d == m) {
		return get_dist();
	}

	for (i = c; i <= chicken_n - m + d; i++) {
		checking_chicken_x[d] = chicken_x[i];
		checking_chicken_y[d] = chicken_y[i];
		tmp_ans = checking(i + 1, d + 1);
		if (tmp_ans < ans)
			ans = tmp_ans;
	}
	return ans;
}


int main() {
	int i, j;
	int c;

	house_n = 0;
	chicken_n = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &c);
			if (c == 1) {
				house_x[house_n] = i;
				house_y[house_n] = j;
				house_n++;
			}
			else if (c == 2) {
				chicken_x[chicken_n] = i;
				chicken_y[chicken_n] = j;
				chicken_n++;
				c = 0;
			}
		}
	}

	printf("%d\n", checking(0, 0));

}
