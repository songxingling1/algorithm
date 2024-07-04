#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) printf("*");
    puts("");
    for (int i = 2; i <= m - 1; i++) {
        printf("*");
        for (int i = 2; i <= n - 1; i++) printf(" ");
        printf("*");
        puts("");
    }
    for (int i = 1; i <= n; i++) printf("*");
    puts("");
    printf("%d\n", 2 * (n - 1) + 2 * (m - 1));
    return 0;
}