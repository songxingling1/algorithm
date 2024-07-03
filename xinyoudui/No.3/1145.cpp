#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, a = 0, b = 0, c = 0;
    while (scanf("%d", &x) != EOF) {
        if (x == -1) break;
        switch (x) {
            case 1:
                a++;
                break;
            case 2:
                b++;
                break;
            case 3:
                c++;
                break;
        }
    }
    printf("A=%d\n", a);
    printf("B=%d\n", b);
    printf("C=%d\n", c);
    printf("Tot=%d\n", a + b + c);
    if (a > (a + b + c) / 2) printf("A-yes\n");
    else if (b > (a + b + c) / 2) printf("B-yes\n");
    else if (c > (a + b + c) / 2) printf("C-yes\n");
    else printf("all-NO\n");
    return 0;
}