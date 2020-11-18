#include<stdio.h>

// 【代码 1】
typedef enum {
    A, B, C, D
} EnumType;

EnumType f(int yr) {
    if (0 == yr % 400) {
        return A;
    } else {
        if (!(yr % 4)) {
            if (0 != yr % 100)
                return B;
            else
                return C;
        }
    }
    return D;
}

// 【代码2 】

int main() {
    int score;
    scanf("%d", & score);
    switch (score) {
        case 5:
            printf("Excellent!\n");
        case 4:
            printf("Good!\n");
            break;
        case 3:
            printf("Average!\n");
        case 2:
        case 1:
        case 0:
            printf("Poor!\n");
        default:
            printf("Oops,Error\n");
    }
    return 0;
}

// 【代码3】

int main() {
    int i, j, k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 2; k++) {
                if (i != j && j != k)
                    printf("%d %d %d\n", i, j, k);
            }
    return 0;
}

// 【问题1 】(4分)
// 对于代码1,写出下面的函数调用后x1 、x2、x3和x4的值。
// x1 = f(1997); D 3
// x2 = f(2000); A 0
// x3 = f(2100); B 2
// x4 = f(2020); C 1

// 【问题2】（5分）
// （1）写出代码2进行时输入为3的输出结果；Average Poor Oops,Error
// （2）写出代码2进行时输入为5的输出结果。Excellent Good

// 【问题3】（6分）
// 写出代码3运行后的输出结果。
/*
    0 1 0
    0 2 0
    0 2 1
    1 0 1
    1 2 0
    1 2 1
*/