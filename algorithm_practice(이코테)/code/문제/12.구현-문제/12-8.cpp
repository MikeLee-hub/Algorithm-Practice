// 12-8. ���ڿ� ������(p.322)

/*
	char �ϳ��� �Է� �޾Ƽ� ó��
*/
#include <stdio.h>
#include <stdlib.h>

int static compare(const void* first, const void* second)
{
    if (*(char*)first > * (char*)second)
        return 1;
    else if (*(char*)first < *(char*)second)
        return -1;
    else
        return 0;
}

char s[10005];
int main() {
	int len = 0;
    int sum = 0;
    char c;

    while (1) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0')
            break;
        if (c >= '0' && c <= '9')
            sum += (int)(c - '0');
        else if (c >= 'A' && c <= 'Z') {
            s[len] = c;
            len++;
        }
    }

    qsort(s, len, sizeof(char), compare);
    printf("%s%d\n", s, sum);
}