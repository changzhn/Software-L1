// 当数组中的元素已经排列有序时，可以采用折半查找（二分查找）法查找一个元素。
// 下面的函数biSearch(int r[]，int low，int high，int key)用非递归方式在数组r中进行二分查找，
// 函数biSearch_rec(int r[]，int low，int high，int key)采用递归方式在数组r中进行二分查找，
// 函数的返回值都为所找到元素的下标；若找不到，则返回-1。

int biSearch1(int r[], int low, int high, int key) {
    // r[low..high] 中的元素按非递减顺序排列
    // 用二分查找法在数组r中查找与key相同的元素
    // 若找到则返回该元素在数组r的下标，否则返回-1

    int mid;

    // while((1))
    while(low <= high) {
        mid = (low + high) / 2;
        if (r[mid] == key) {
            return mid;
        } else if (key < r[mid]) {
            // (2)
            high = mid - 1;
        } else {
            // (3)
            low = mid + 1;
        }
    }

    return -1;
}

int biSearch2(int r[], int low, int high, int key) {
    int mid;

    // if ((4)) {
    if (low <= high) {
        mid = (low + high) / 2;
        if (r[mid] == key) {
            return mid;
        } else if (key < r[mid]) {
            // return biSearch2((5), key);
            return biSearch2(r, low, mid - 1, key);
        } else {
            // return biSearch2((6), key);
            return biSearch2(r, mid + 1, high, key);
        }
    }

    return -1;
}

// 问题2 】(3分）
// 若有序数组中有n个元素，采用二分查找法查找一个元素时，最多与（  ）个数组元素进行比较，即可确定查找结果。
// （7）备选答案：
// A.[log2(n+1)]        B.[n/2]        C.n-1        D.n

// A