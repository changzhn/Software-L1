#include <stdio.h>

int main()
{
    int a, tmp, b = 0;
    scanf("%d", &a);

    tmp = a < 0 ? -a : a;

    while(tmp) {
        b = b * 10 + tmp % 10;
        tmp = tmp / 10;
    }

    if (a == b || -a == b) {
        printf("回文 number.\n");
    }

    printf("a = %d b = %d\n", a, b);
    return 0;
}

// 输出 -1331 795的结果