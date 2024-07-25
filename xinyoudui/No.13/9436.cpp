#include <bits/stdc++.h>
using namespace std;
char s[6561][6561];
const int base[8] = {1, 3, 9, 27, 81, 243, 729, 2187};
void generic(int n, int x, int y) {
    if (n == 1) {
        s[x][y] = 'x';
        return;
    }
    generic(n - 1, x, y);
    generic(n - 1, x, y + base[n - 2] * 2);
    generic(n - 1, x + base[n - 2], y + base[n - 2]);
    generic(n - 1, x + 2 * base[n - 2], y);
    generic(n - 1, x + 2 * base[n - 2], y + 2 * base[n - 2]);
}
void print(int n) {
    for (int i = 0; i < base[n - 1]; i++) {
        for (int j = 0; j < base[n - 1]; j++) {
            if (s[i][j] == '\0') printf(" ");
            else printf("x");
        }
        puts("");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    generic(n, 0, 0);
    print(n);
    return 0;
}