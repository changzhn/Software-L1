#include <stdio.h>

// 对n个元素进行简单选择排序的基本方法是：第一趟从第1个元素开始，在n个元素中选出最小者，
// 将其交换至第一个位置，第二趟从第2个元素开始，在剩下的n-1个元素中选出最小者，将其交换至第二个位置，
// 依此类推，第i趟从n-i+1个元素中选出最小元素，将其交换至第i个位置，
// 通过n-1趟选择最终得到非递减排序的有序序列。

// 对 data[0]~data[n-1]中的n个整数按非递减有序的方式进行排列
void selectSort(int data[], int n) {
    int i, j, k;
    int tmp;

    for (i = 0; i < n; i++) {
        // k表示data[i]~data[n-1]中最小元素的下标
        // for(k = i, j = i + 1;(1);(2)) {
        for(k = i, j = i + 1; j < n; j++) {
            if (data[j] < data[k]) {
                // (3)
                k = j;
            }

            if (k != i) {
                // 将本趟找出的最小元素与data[i]交换
                tmp = data[i]; 
                //（4） ;
                data[i] = data[k];
                data[k] = tmp;
            }
        }
    }
}

int main()
{
       int arr[ ]={79,85,93,65,44,70,100,57};
       int i, m;
       m = sizeof(arr) / sizeof(int);             //计算数组元素的个数，用m表示
       // (5）;                                         //调用selectSort对数组arr进行非递减排序
       selectSort(arr, m);
       // for(（6）;i <m;i++)                      //按非递减顺序输出所有的数组元素             
       for(i = 0; i <m; i++)                      //按非递减顺序输出所有的数组元素             
            printf("%d\t", arr[i]);
       printf("\n");
       return 0;
}