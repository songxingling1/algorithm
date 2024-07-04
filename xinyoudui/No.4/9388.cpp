#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int a = 2, b, flag = 0;
    while (true) {
        flag = 0;
        for (b = 1; b <= a; b++) {
            if (a * (a + 1) / 2 - 3 * b == n) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
        a++;
    }
    printf("%d %d\n", b, a);
    return 0;
}