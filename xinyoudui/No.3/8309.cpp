#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a = 1, b = 1;
    scanf("%d", &n);
    if (n >= 1) {
        printf("1 ");
    }
    if (n >= 2) {
        printf("1 ");
    }
    for (int i = 3, tmp; i <= n; i++) {
        tmp = a + b;
        printf("%d ", tmp);
        a = b;
        b = tmp;
    }
    puts("");
    return 0;
}