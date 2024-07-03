#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, cnt = 0;
    scanf("%d", &x);
    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
        } else {
            x = x * 3 + 1;
        }
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}