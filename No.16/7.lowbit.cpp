#include <bits/stdc++.h>
using namespace std;
inline int lowbit(int x) {
    return x & (-x);
}
int main() {
    int x;
    scanf("%d", &x);
    printf("%d = ", x);
    while (x) {
        printf("%d", lowbit(x));
        x -= lowbit(x);
        if (x != 0) printf(" + ");
    }
    puts("");
    return 0;
}