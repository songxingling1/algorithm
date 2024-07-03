#include <bits/stdc++.h>
using namespace std;
int check(int x) {
    while (x) {
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}
int main() {
    for (int i = 10; i <= 99; i++) {
        if (i % 7 == 0 || check(i)) {
            printf("pass! ");
        } else {
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
}