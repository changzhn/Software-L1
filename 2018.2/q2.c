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

int main()
{
    char grade;
    int points;

    for(grade = 'A'; grade < 'F'; grade++) {
        switch(grade) {
            case 'A': points = 4; break;
            case 'B': points = 3;
            case 'C': points = 2;
            case 'D': points = 1; break;
            case 'E': 
            case 'W': points = 0;
        }
        printf("points = %d\n", points);
    }

    return 0;
}