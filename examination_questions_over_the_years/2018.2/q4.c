#include <stdio.h>
#define ARRSZ 3

void insertElement(double arr[], int n, double elem) {
    int i;
    double tmp;

    if (n == 0 || elem == arr[n - 1]) {
        arr[n] = elem;
        return;
    }

    for(i = n - 1; i >= 0 && elem < arr[i]; i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = elem;
}

int main()
{
    int idx, n = 0;
    double price, pdata[ARRSZ];

    do {
        scanf("%lf", &price);
        if (price < 0) {
            continue;
        }
        insertElement(pdata, n, price);
        n++;
    } while (n < ARRSZ);

    for (idx = 0; idx < n; idx++) {
        printf("%.2lf\n", pdata[idx]);
    }
    return 0;
}