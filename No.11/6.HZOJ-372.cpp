#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    scanf ("%d", &n);
    vector<int> arrA (n + 1), arrB (n + 1);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &arrA[i]);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &arrB[i]);
    stack<int> sta, stb;
    int p;
    for (p = 1; p <= n; p++) {
        while (!sta.empty () && arrA[sta.top ()] >= arrA[p])
            sta.pop ();
        while (!stb.empty () && arrB[stb.top ()] >= arrB[p])
            stb.pop ();
        sta.push (p);
        stb.push (p);
        if (sta.size () != stb.size ())
            break;
    }
    printf ("%d\n", p - 1);
    return 0;
}
