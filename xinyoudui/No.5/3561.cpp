#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;
int a[MAX_N + 5];
int main() {
    int n, m, flag;
    while (scanf("%d", &n) != EOF) {
        flag = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        scanf("%d", &m);
        for (int i = 0; i < n; i++) {
            if (a[i] == m) {
                printf("%d\n", i);
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("No\n");
        }
    }
    return 0;
}