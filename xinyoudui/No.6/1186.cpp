#include <bits/stdc++.h>
using namespace std;
int main() {
    int xx, yy;
    for (int i = 1, t; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &t);
            if (t == 1) {
                xx = i;
                yy = j;
            }
        }
    }
    printf("%d\n", abs(xx - 3) + abs(yy - 3));
    return 0;
}