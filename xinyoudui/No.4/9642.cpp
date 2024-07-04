#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    scanf("%d", &m);
    for (int i = m; i >= 0; i--) {
        for (int j = 0; j < m - i; j++) printf("o");
        printf("x");
        for (int j = 0; j < 2 * i - 1; j++) printf("o");
        if (i > 0) printf("x");
        for (int j = 0; j < m - i; j++) printf("o");
        puts("");
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < m - i; j++) printf("o");
        printf("x");
        for (int j = 0; j < 2 * i - 1; j++) printf("o");
        if (i > 0) printf("x");
        for (int j = 0; j < m - i; j++) printf("o");
        puts("");
    }
    return 0;
}