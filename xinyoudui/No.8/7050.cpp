#include <bits/stdc++.h>
using namespace std;
int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int check() {
    int ka = a[0] * 100 + a[1] * 10 + a[2];
    int kb = a[3] * 100 + a[4] * 10 + a[5];
    int kc = a[6] * 100 + a[7] * 10 + a[8];
    if (kb == 2 * ka && kc == 3 * ka) return 1;
    return 0;
}
int main() {
    do {
        if (check()) {
            printf("%d%d%d %d%d%d %d%d%d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
        }
    } while(next_permutation(a,a + 9));
    return 0;
}