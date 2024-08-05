#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5];
char op[4];
int main() {
    bool isZero = false;
    bool isTimes = false;
    for (int i = 1; i <= 4; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 0) isZero = true;
    }
    for (int i = 1; i <= 3; i++) {
        do {
            scanf("%c", &op[i]);
        } while (op[i] != '+' && op[i] != '*');
        if (op[i] == '*') isTimes = true;
    }
    if (isZero && isTimes) {
        printf("0\n");
        return 0;
    }
    sort(a + 1, a + 5);
    sort(op + 1, op + 4);
    for (int i = 1; i <= 3; i++) {
        if (op[i] == '*') {
            a[i + 1] *= a[i];
        } else {
            a[i + 1] += a[i];
        }
        a[i] = 0;
        sort(a + 1, a + 5);
    }
    printf("%lld", a[4]);
    return 0;
}