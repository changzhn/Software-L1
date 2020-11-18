#include <stdio.h>
#define PM25_L1 200
#define PM25_L2 400

typedef enum {
    YES, NO
} MARKTAG;

int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

void prt_msg(char *msg, MARKTAG flag) {
    if (flag == YES) {
        printf("%s : traffic restrictions\n", msg);
    } else {
         printf("%s : free\n", msg);
    }
}

// 判断是否符合限行规则，是则返回1，否则返回0
int isMatched(int weekday, int t, int d) {
    return (weekday % d == t % d);
}

void proc(int pm25, int weekday, char *licence) {
    int i, lastd;

    //  if (weekday == 6 || weekday == 7 || (1)) {
    if (weekday == 6 || weekday == 7 || pm25 < PM25_L1) {
        prt_msg(licence, NO);
    } else {
        for (i = 5; i >= 0; i--) {
            if (isDigit(licence[i])) {
                // lastd = (2) TODO:
                lastd = licence[i] - '0';
                break;
            }
        }

        if (pm25 >= PM25_L2) {
            // if (isMatched((4)))
            if (isMatched(weekday, lastd, 2)) {
                prt_msg(licence, YES);
            } else {
                prt_msg(licence, NO);
            }
        } else {
            // if (isMatched())
            if (isMatched(weekday, lastd, 5)) {
                prt_msg(licence, YES);
            } else {
                prt_msg(licence, NO);
            }
        }
    }
}

int main()
{
    int weekday = 0, pm25 = 0;
    char licence[7];
    scanf("%d %d %s",&pm25, &weekday, licence);
    //输入数据的有效性检测略，下面假设输入数据有效、正确 
    // proc(     （5）      );
    proc(pm25, weekday, licence);
    return 0;
}