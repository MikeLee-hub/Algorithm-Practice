// 4-2. 왕실의 나이트 (p.115)

/*
	걍 모든 경우의 수 계산
	구역을 나눠서 계산할 수 도 있음
*/
#include <stdio.h>

int h_move[8] = { 1, 2, 2 ,1 ,-1, -2, -2, -1 };
int y_move[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
	char hang, yeul, tmp;
	int new_h, new_y;
	int ans = 0;
	int i;

	scanf("%c%c", &hang, &yeul);
	if (hang >= '1' && hang <= '8') {
		tmp = hang;
		hang = yeul;
		yeul = tmp;
	}
	hang -= 'a';
	yeul -= '1';

	for (i = 0; i < 8; i++) {
		new_h = (int)hang + h_move[i];
		new_y = (int)yeul + y_move[i];
		if (new_h < 0 || new_h >= 8)
			continue;
		if (new_y < 0 || new_y >= 8)
			continue;
		ans++;
	}
	printf("%d", ans);
}