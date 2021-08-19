// 14-23. ������(p.359) (���� 10825��)

/*
	�����͸� struct�� ����
	stdlib�� qsort ����Ͽ� sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[11];
	int k;
	int e;
	int m;
}student;

student s[100005];

int comp(const void* aa, const void* bb) {
	student a, b;
	a = *((student*)aa);
	b = *((student*)bb);
	if (a.k > b.k)
		return -1;
	else if (a.k < b.k)
		return 1;

	if (a.e > b.e)
		return 1;
	else if (a.e < b.e)
		return -1;

	if (a.m > b.m)
		return -1;
	else if (a.m < b.m)
		return 1;

	return strcmp(a.name, b.name);
}

int main() {
	int n;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s%d%d%d", s[i].name, &(s[i].k), &(s[i].e), &(s[i].m));

	qsort(s, n, sizeof(student), comp);

	for (i = 0; i < n; i++)
		printf("%s\n", s[i].name);
	return 0;
}