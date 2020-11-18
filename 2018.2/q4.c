#include <stdio.h>
#define ARRSZ 3

// 函数insertElem 的功能是在元素升序排列的数组中加入一个新元素并保持数组元素升序排列的特点。
// 在main函数中输入若干表示价格的实数，输入为0或负数或实数个数超出限定数量时终止，
// 调用insertElem将价格按升序保存在数组pdata中，最后输出所输入的实数。

/*arr 空间足够大且其元素按照升序排列，将elem插入arr中并保持其升序特点*/
void insertElement(double arr[], int n, double elem) {
    int i;
    double tmp;

    if (n == 0 || elem == arr[n - 1]) {
        // (1) = elem;
        arr[n] = elem;
        return;
    }

    for(i = n - 1; i >= 0 && elem < arr[i]; i--) {
        // (2)
        arr[i + 1] = arr[i];
    }
    // (3) = elem;
    arr[i + 1] = elem;
}

int main()
{
    int idx, n = 0;
    double price, pdata[ARRSZ];

    do {
        scanf("%lf", &price);
        if (price < 0) {
            // (4)
            break;
        }
        // insertElement((5));
        insertElement(pdata, n, price);
        n++;
    } while (n < ARRSZ);

    // for (idx = 0; (6); idx++) {
    for (idx = 0; idx < n; idx++) {
        printf("%.2lf\n", pdata[idx]);
    }
    return 0;
}