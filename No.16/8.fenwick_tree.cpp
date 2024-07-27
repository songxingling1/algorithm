#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
int a[10005];
int c[10005];
void add(int pos, int x, int n) {
    while (pos <= n) {
        c[pos] += x;
        pos += lowbit(pos);
    }
}
int query(int x) {
    int sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        add(i, a[i], n);
    }
    printf("a : ");
    for (int i = 1; i <= n; i++) {
        printf("%4d ", a[i]);
    }
    puts("");
    printf("c : ");
    for (int i = 1; i <= n; i++) {
        printf("%4d ", c[i]);
    }
    puts("");
    printf("s : ");
    for (int i = 1; i <= n; i++) {
        printf("%4d ", query(i));
    }
    puts("");
    return 0;
}