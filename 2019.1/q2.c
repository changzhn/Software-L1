
// 函数bubbleSort(int arr[], int n, int (*compare)(int,int))的功能是根据调用时传递的比较函数compare对数组arr的前n个元素进行排序。

#define swap(a, b) { a = a^b; b = a^b; a = a^b;} //交换a与b的值

int less(int x, int y)
{
     return ((x<y) ? 1 : 0);
}

int larger(int x, int y)
{
     return ((x>y) ? 1 : 0);
}

void bubbleSort(int arr[ ], int n, int (*compare)(int,int))
{      
    int i,j;
    int swapped = 1;
    for( i=0; swapped; i++) {
        swapped = 0;
        for(j=0; j<n-1-i; j++) {
            if ( compare( arr[j+1], arr[j])) {
                swap( arr[j+1], arr[j]);
                swapped =1;
            }
        }
    }
}

// 设有如下数组定义：
// int data1[ ] = {4, 2, 6, 3, 1};
// int data2[ ] = {4, 2, 6, 3, 1};
// int data3[ ] = {4, 2, 6, 3, 1};
// 请分别给出下面的函数调用执行后，数组data1、data2和data3各自的元素序列。
// (1)bubbleSort(data1, 5, less);
// (2) bubbleSort(data2, 5, larger);
// (3) bubbleSort(data3, 3, larger);