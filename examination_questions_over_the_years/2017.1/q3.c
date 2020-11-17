
typedef struct {
    char *str;
    int length;
    int capacity;
} SString;


int indexStr(SString S, SString T, int pos) {
    int i, j;
    if (S.length < 1 || T.length < 1 || S.length < pos + T.length - 1) {
        return -1;
    }
    for (i = pos, j = 0; i < S.length, j < T.length;) {
        if (S.str[i] == T.str[i]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.length) {
        return i - T.length;
    }
    return -1;
}

void eraseStr(SString S, SString T) {
    int i;
    int pos;
    if (S.length < 1 || T.length < 1 || S.length < T.length) {
        return;
    }

    pos = 0;

    for(;;) {
        pos = indexStr(S, T, pos);
        if (pos == -1) {
            return;
        }

        for(i = pos + T.length; i < S.length; i++) {
            S.str[i - T.length] = S.str[i];
        }
        S.length = S.length - T.length;
    }
}