#include <stdio.h>

int factorial(int n) {
    int a = 1;
    for (int i = 1; i <= n; i++) {
        a = a * i;
    }
    return a;
}

int isPrime(int p) {
    int ans = 1;
    if (p == 0)
        return 0;
    if (p == 1 || p == 2)
        return 1;
    for (int i = 2; i <= p / 2; i++) {
        if (p % i == 0)
            ans = 0;
    }
    return ans;
}

int isStrong(int p) {
    if (p == 0) {
        return 0;
    }
    int ans = 1;
    int a = p;
    int sum = 0;
    while (a != 0) {
        int x = factorial(a % 10);
        sum = sum + x;
        a = a / 10;
    }
    if (sum != p)
        ans = 0;
    return ans;
}