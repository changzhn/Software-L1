#include <stdio.h>

typedef struct {
    char *str;
    int length;
    int capacity;
} SString;

// 函数indexStr（S,T,pos）的功能是：在S 所表示的字符串中，
// 从下标pos开始查找T所表示字符串首次出现的位置。
// 方法是：第一趟从S中下标为pos、T中下标为0的字符开始，
// 从左往右逐个对于来比较S和T的字符，直到遇到不同的字符或者到达T的末尾。
// 若到达T的末尾，则本趟匹配的起始下标pos为T出现的位置，结束查找；若遇到了不同的字符，
// 则本趟匹配失效。下一趟从S中下标pos+1处的字符开始，重复以上过程。若在S中找到T，
// 则返回其首次出现的位置，否则返回-1。

int indexStr(SString S, SString T, int pos) {
    printf("S.length = %d T.length = %d\n", S.length, T.length);
    int i, j;
    if (S.length < 1 || T.length < 1 || S.length < pos + T.length - 1) {
        return -1;
    }

    for (i = pos, j = 0; i < S.length, j < T.length;) {
        if (S.str[i] == T.str[j]) {
            i++;
            j++;
        } else {
            // i = (1)
            i = i - j + 1;
            j = 0;
        }
    }

    // if ((2)) {
    if (j == T.length) {
        printf("i = %d\n", i);
        return i - T.length;
    }
    return -1;
}

// 函数 eraseStr（S，T}的功能是删除字符串S中所有与T相同的子串，其处理过程为: 
// 首先从字符串 S 的第一个字符（下标为0）开始查找子串T，若找到〈得到子串在S中的起始位置），
// 则将串 S 中子串T之后的所有字符向前移动，将子串T覆盖，从而将其删除，
// 然后重新开始查找下一个子串T，若找到就用后面的宇符序列进行覆盖，重复上述过程，
// 直到将S中所有的子串T删除。

void eraseStr(SString S, SString T) {
    int i;
    int pos;
    if (S.length < 1 || T.length < 1 || S.length < T.length) {
        return;
    }

    pos = 0;

    for(;;) {
        // pos = indexStr((3))
        pos = indexStr(S, T, pos);
        if (pos == -1) {
            return;
        }

        for(i = pos + T.length; i < S.length; i++) {
            // S.str[(5)] = S.str[i];
            S.str[i - T.length] = S.str[i];
        }
        // S.length = (6);
        S.length = S.length - T.length;
    }
}

int main()
{
    // SString S, T;

    // S.str = "abcde\0";
    // S.length = 6;

    // T.str = "ab\0";
    // T.length = 3;

    SString S = {"1hello\0", 7};
    SString T = {"he\0", 3};

    // int ret = indexStr(S, T, 0);
    // printf("indexStr ret = %d\n", ret);

    eraseStr(S, T);
    printf("S.str = %s\n", S.str);

    return 0;
}