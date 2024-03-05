#include <bits/stdc++.h>
using namespace std;
long long total = 0;
int n, k;
int x[25];
bool isPrime (int x) {
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
void search (int top, int step, int sum) {
    if (step == k) {
        if (isPrime (sum))
            total++;
        return;
    }
    for (int i = top; i <= n; i++) {
        search (i + 1, step + 1, sum + x[i]);
    }
}
int main () {
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &x[i]);
    search (1, 0, 0);
    printf ("%lld\n", total);
    return 0;
}
