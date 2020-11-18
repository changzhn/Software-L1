#include <stdio.h>

// 直接插入排序是一种简单的排序方法，具体做法是：在插入第i个关键码时，k1，k2，…，ki-1已经排好序，这时将关键码ki依次与关键码ki-1，ki-2，…，进行比较，找到ki应该插入的位置时停下来，将插入位置及其后的关键码依次向后移动，然后插入ki。
// 例如，对｛17，392，68，36｝按升序作直接插入排序时，过程如下：
// 第1次：将392（i＝1）插入有序子序列{17}，得到{17，392}；
// 第2次：将68（i＝2）插入有序子序列{17，392}，得到{17，68，392}；
// 第3次：将36（i＝3）插入有序子序列{17，68，392}，得到{17，36，68，392}，完成排序。
// 下面函数 insertSort用直接插入排序对整数序列进行升序排列，在main函数中调用insertSort并输出排序结果。

void insertSort(int data[], int n)
{
    int i, j, tmp;

    for(i = 1; i < n; i++) {
        if (data[i] < data[i - 1]) {
            tmp = data[i];
            // data[i] = (1)
            data[i] = data[i - 1];
            data[i - 1] = tmp;

            for(j = i - 2; j >= 0 && data[j] > tmp; j--) {
                // (2)
                data[j + 1] = data[j];
            }
            // (3) = tmp;
            data[j + 1] = tmp;
        }
    }
}

int main()
{
    int *bp, *ep;
    int n, arr[] = {17, 392, 68, 36, 291, 776, 843, 255};
    n = sizeof(arr) / sizeof(int);
    insertSort(arr, n);
    // bp = (4)
    bp = arr;
    ep = arr + n;
    for(;bp < ep; bp++) {
        // printf("%d\n", (5));
        printf("%d\n", *bp);
    }
    return 0;
}