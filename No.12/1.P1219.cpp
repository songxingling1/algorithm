#include <bits/stdc++.h>
#define MAX_N 13
using namespace std;
int column = 0, l = 0, r = 0;
int ans[MAX_N + 1] = { 0 };
int total = 0;
int n;
void print () {
    total++;
    if (total > 3)
        return;
    for (int i = 1; i <= n; i++)
        printf ("%d ", ans[i]);
    puts ("");
}
void search (int x) {
    for (int i = 1; i <= n; i++) {
        if (!(column & (1 << i)) && !(l & (1 << (x - i + MAX_N)))
            && !(r & (1 << (x + i)))) {
            ans[x] = i;
            column += 1 << i;
            l += 1 << (x - i + MAX_N);
            r += 1 << (x + i);
            if (x == n)
                print ();
            else
                search (x + 1);
            column -= 1 << i;
            l -= 1 << (x - i + MAX_N);
            r -= 1 << (x + i);
        }
    }
}
int main () {
    scanf ("%d", &n);
    search (1);
    printf ("%d\n", total);
    return 0;
}
