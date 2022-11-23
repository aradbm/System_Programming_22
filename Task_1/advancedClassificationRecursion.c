#include <stdio.h>

int Pow(int a, int b) {
    int num = 1;
    for (int i = 0; i < b; i++) {
        num *= a;
    }
    return num;
}

int getLength(int p) {
    int len = 1;
    while (p > 9) {
        len = len + 1;
        p = p / 10;
    }
    return len;
}

int getRev(int p) {
    int len = getLength(p) - 1;
    if (p < 10)
        return p;
    return (p % 10) * Pow(10, len) + getRev(p / 10);
}

int isPalindrome(int p) {
    int a = getRev(p);
    if (a == p)
        return 1;
    return 0;
}

int isArmstrong_ad(int p, int a) {
    if (p < 10)
        return Pow(p, a);
    return Pow(p % 10, a) + isArmstrong_ad(p / 10, a);
}

int isArmstrong(int p) {
    int a = isArmstrong_ad(p, getLength(p));
    if (p == a)
        return 1;
    return 0;
}
