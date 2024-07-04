#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
void print(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (n - i) * 4; j++) printf(" ");
        for (int j = 0; j < i; j++) {
            printf(" O      ");
        }
        puts("");
        for (int j = 0; j < (n - i) * 4; j++) printf(" ");
        for (int j = 0; j < i; j++) {
            printf("/|\\     ");
        }
        puts("");
        for (int j = 0; j < (n - i) * 4; j++) printf(" ");
        for (int j = 0; j < i; j++) {
            printf("/ \\     ");
        }
        puts("");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    print(n);
    return 0;
}