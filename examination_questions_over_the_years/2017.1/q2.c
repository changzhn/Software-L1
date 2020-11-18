#include <stdio.h>
#include <ctype.h>

// 函数 isLegal(char*ipaddr)的功能是判断以点分十进制数 表示的 iPV4 地址是否合法。
// 参数 ipadddr 给出表示 iPV4 地址的字 符串的首地址，串中仅含数字字符和“.”。
// 若 iPV4 地址合法则返回 1，否则反馈 0.判定伟合法的条件是:每个十进制数的值位于整数区 间[0,255]，
// 两个相邻的树之间用“.”分隔，共 4 个数、3 个“.”。; 例如，192.168.0.15、1.0.0.1 是合法的，
// 192.168.1.256、1.1..1是不合法的。


int isLegal(char *ipaddr) {
    printf("ip = %s\n", ipaddr);

    int flag;
    int curVal; // 表示当前的十进制数
    int decNum = 0, dotNum = 0;

    // char *p = (1);
    char *p = ipaddr;

    for(; *p; p++) {
        curVal = 0;
        flag = 0;

        while(isdigit(*p)) {
            // curVal = (2) + *p - '0';
            curVal = curVal * 10 + *p - '0';
            // (3)
            p++;
            flag = 1;
        }

        if (curVal > 255) {
            return 0;
        }

        if (flag) {
            // (4)
            decNum++;
        }

        if (*p == '.') {
            dotNum++;
        }
    }

    // if ((5)) {
    if (decNum == 4 && dotNum == 3) {
        return 1;
    }
    return 0;
}

int main()
{
    char ip[] = "1.1..1";
    int ret = isLegal(ip);
    printf("ret = %d\n", ret);
    return 0;
}