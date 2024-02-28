#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, k;
    scanf ("%d%d", &n, &k);
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &arr[i]);
    }
    deque<int> minn, maxn;
    vector<int> minAns (n + 1), maxAns (n + 1);
    for (int i = 1; i <= n; i++) {
        while (!minn.empty () && arr[minn.back ()] >= arr[i])
            minn.pop_back ();
        while (!maxn.empty () && arr[maxn.back ()] <= arr[i])
            maxn.pop_back ();
        minn.emplace_back (i);
        maxn.emplace_back (i);
        if (i - minn.front () == k)
            minn.pop_front ();
        if (i - maxn.front () == k)
            maxn.pop_front ();
        minAns[i] = arr[minn.front ()];
        maxAns[i] = arr[maxn.front ()];
    }
    for (int i = k; i <= n; i++) {
        if (i != k)
            printf (" ");
        printf ("%d", minAns[i]);
    }
    puts ("");
    for (int i = k; i <= n; i++) {
        if (i != k)
            printf (" ");
        printf ("%d", maxAns[i]);
    }
    puts ("");
    return 0;
}
