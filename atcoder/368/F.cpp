#include <bits/stdc++.h>
using namespace std;
int d[100005];
int main() {
    for (int i = 2; i <= 100000; i++) {
        d[i] = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                d[i] += d[i / j];
                break;
            }
        }
    }
    int n;
    scanf("%d", &n);
    int ret = 0;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        ret ^= d[a];
    }
    if (ret) {
        puts("Anna");
    } else {
        puts("Bruno");
    }
    return 0;
}