#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    scanf("%d", &m);
    for (int i = m; i >= 1; i--) {
        for (int j = 0; j < m - i; j++) printf(" ");
        for (int j = 0; j < 2 * i - 1; j++) printf("%d", i);
        for (int j = 0; j < m - i; j++) printf(" ");
        puts("");
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 0; j < m - i; j++) printf(" ");
        for (int j = 0; j < 2 * i - 1; j++) printf("%d", i);
        for (int j = 0; j < m - i; j++) printf(" ");
        puts("");
    }
    return 0;
}