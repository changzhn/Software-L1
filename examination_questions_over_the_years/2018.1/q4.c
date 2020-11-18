#include <stdio.h>
#define NUMBER 100

// 下面的C代码在输入的100个英文单词中找出最小单词和最大单词。
// 约定每个单词是仅由英文字母构成的字符串，且都不超过20个字符。
// 单词的大小按照字典序定义。例如，单词“entry”大于“enter”、
// “art”小于“ article”、“an”等于“An”。

// 若字符串s1仅包含英文字母则返回1，否则返回0
int isValid(const char *s1);

// 将大写字母转成小写字母
char toLower(char ch);

// 比较字符串s1和s2是否相等，相等时返回0
// s1大时返回正数 s2大时返回负数
int usr_strcmp(char *s1, char *s2);

// 将s2拷贝给s1
void usr_strcpy(char *s1, char *s2);

int main()
{
    char word[32];
    char maxWord[32] = "", minWord[32] = "";
    int numWord = 0;

    while(numWord < NUMBER) {
        // scanf("%s", (1));
        scanf("%s", word);
        if (isValid(word)) {
            if (numWord == 0) {
                usr_strcpy(minWord, word);
                usr_strcpy(maxWord, word);
            }
            numWord++;
            // if ((2)) > 0) {
            if (usr_strcmp(word, maxWord) > 0) {
                usr_strcpy(maxWord, word);
            // } else if ((3)) < 0) {
            } else if (usr_strcmp(word, minWord) < 0) {
                usr_strcpy(minWord, word);
            }
        }
    }

    printf("maxWord=%s, minWord=%s", maxWord, minWord);

    return 0;
}

int isValid(const char *s) {
    for(; *s; s++) {
        if (!(*s >= 'a' && *s <= 'z') && !(*s >= 'A' && *s <= 'Z')) {
            return 0;
        }
    }
    return 1;
}

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        //  ch = (4) + 'a';
        ch = ch - 'A' + 'a';
    }
    return ch;
}

int usr_strcmp(char *s1, char *s2) {
    // for(;(5);) {
    for(;*s1 || *s2;) {
        if (toLower(*s1) == toLower(*s2)) {
            s1++;
            s2++;
        } else {
            break;
        }
    }
    return (toLower(*s1) - toLower(*s2));
}

void usr_strcpy(char *s1, char *s2) {
    // for(;(6);) {
    for(;*s2;) {
        *s1++ = *s2++;
    }
    *s1 = '\0';
}