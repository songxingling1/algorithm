#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    scanf ("%d", &n);
    vector<int> arra (n + 1), arrb (n + 1);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &arra[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &arrb[i]);
    }
    stack<int> q1, q2;
    int p;
    for (p = 1; p <= n; p++) {
        while (!q1.empty () && arra[q1.top ()] > arra[p])
            q1.pop ();
        while (!q2.empty () && arrb[q2.top ()] > arrb[p])
            q2.pop ();
        q1.push (p);
        q2.push (p);
        if (q1.size () != q2.size ())
            break;
    }
    printf ("%d\n", p - 1);
    return 0;
}
