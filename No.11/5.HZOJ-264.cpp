#include <bits/stdc++.h>
using namespace std;
int main () {
    long long n;
    scanf ("%lld", &n);
    vector<long long> arr (n + 1), min1 (n + 2), min2 (n + 2);
    arr[0] = -1;
    for (long long i = 1; i <= n; i++) {
        scanf ("%lld", &arr[i]);
    }
    arr.push_back (-1);
    stack<long long> s1, s2;
    for (long long i = 0; i <= n + 1; i++) {
        while (!s1.empty () && arr[s1.top ()] > arr[i]) {
            min1[s1.top ()] = i;
            s1.pop ();
        }
        s1.push (i);
    }
    for (long long i = n + 1; i >= 0; --i) {
        while (!s2.empty () && arr[s2.top ()] > arr[i]) {
            min2[s2.top ()] = i;
            s2.pop ();
        }
        s2.push (i);
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans = max (ans, arr[i] * (min1[i] - 1 - min2[i]));
    }
    printf ("%lld", ans);
    return 0;
}
