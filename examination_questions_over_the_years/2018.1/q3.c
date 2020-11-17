float adjustSalary(int service_year, int age, float salary) {
    if (service_year <= 5) {
        if (age > 30)
            salary *= 1.2;
    } else
        salary *= 2.0;
    return salary;
}

// x1 = adjustSalary（1,25,9000.0）; --> 9000.0
// x2 = adjustSalary（8,32,7000.0）; --> 14000.0
// x3 = adjustSalary（5,41,5000.0）; --> 6000.0


void foo(int coin) {
    switch (coin) {
        case 1:
            printf("Cent\n");
        case 5:
            printf("Nicke1\n");
            break;
        case 10:
            printf("Dime\n");
        case 25:
            printf("Quarter\n");
    }
}

// （1）写出函数调用为foo(1)的输出结果； --> Cent Nicke1
// （2）写出函数调用为foo(5)的输出结果； --> Nicke1
// （3）写出函数调用为foo(10)的输出结果； --> Dime Quarter
// （4）写出函数调用为foo(25)的输出结果。 --> Quarter


int getSum(int n) {
    int t, i = 0, sum = 0;
    while (i < n) {
        scanf("%d", &t);
        if (t < 0)
            continue;
        sum += t;
        i++;
    }
    return sum;
}

// 求n个不小于0数之和