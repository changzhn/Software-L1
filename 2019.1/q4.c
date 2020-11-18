#include <stdio.h>

//将数字字符串转换为整数
int str2int(char *s);
//判断字符串的开头字符是否为运算符
int isOperator(char *str);

//将数字串转化为对应整数后进行op所要求的计算
void cal(char op, char a[], char b[]); 

void solve(char a[], char b[], char c[]);

int main ()
{
    char a[10],b[10], c[10];
    scanf("%s%s%s",a,b,c);
    //输入数据的有效性检测略,下面假设输入数据有效、正确 
    Solve(a,b,c);
    return 0;
}

int str2int(char *s) {
    int val = 0;
    while(*s) {
        // val = (1) + (*s - '0');
        val = val * 10 + (*s - '0');
        // (2)
        s++;
    }
    return val;
}

int isOperator(char *str)
{
    return (*str =='+' || *str == '-');
}

void cal(char op, char a[], char b[]) {
    switch(op) {
        case '+':
            printf(" ％s + %s = %d",a,b,str2int(a)+str2int(b)); 
            break;
        case '-':
            printf("%s - %s = %d " ,a,b,str2int(a)-str2int(b)); 
            break;
    }
}

void solve(char a[], char b[], char c[]) {
    if (isOperator(a)) {
        // (3)
        cal(*a, b, c);
    } else if (isOperator(b)) {
        // (4)
        cal(*b, a, c);
    } else {
        // (5)
        cal(*c, a, b);
    }
}