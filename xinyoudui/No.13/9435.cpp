#include <bits/stdc++.h>
using namespace std;
char s[2048][2048];
void generic(int n, int x, int y) {
    if (n == 1) {
        s[x][y + 1] = '/';
        s[x][y + 2] = '\\';
        s[x + 1][y] = '/';
        s[x + 1][y + 1] = '_';
        s[x + 1][y + 2] = '_';
        s[x + 1][y + 3] = '\\';
        return;
    }
    generic(n - 1, x, y + (1 << (n - 1)));
    generic(n - 1, x + (1 << (n - 1)), y);
    generic(n - 1, x + (1 << (n - 1)), y + (1 << (n - 2)) * 4);
}
void print(int n) {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < ((1 << (n - 1)) * 4); j++) {
            if (s[i][j] == '\0') printf(" ");
            else printf("%c", s[i][j]);
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