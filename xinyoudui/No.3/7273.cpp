#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    scanf("%d", &x);
    while (x != 1) {
        if (x % 2 == 0) {
            printf("%d/2=%d\n", x, x / 2);
            x /= 2;
        } else {
            printf("%d*3+1=%d\n", x, x * 3 + 1);
            x = x * 3 + 1;
        }
    }
    printf("End\n");
    return 0;
}