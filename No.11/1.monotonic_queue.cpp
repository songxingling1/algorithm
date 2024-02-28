#include <bits/stdc++.h>
using namespace std;
void output (vector<int>& arr) {
    int n = arr.size (), len = 0;
    for (int i = 0; i < n; i++) {
        len += printf ("%3d", i);
    }
    puts ("");
    for (int i = 0; i < len; i++)
        printf ("-");
    puts ("");
    for (int i = 0; i < n; i++) {
        len += printf ("%3d", arr[i]);
    }
    puts ("");
}
int main () {
    int n, k;
    scanf ("%d%d", &n, &k);
    vector<int> arr;
    deque<int> q;
    for (int i = 0, a; i < n; i++) {
        scanf ("%d", &a);
        arr.emplace_back (a);
    }
    output (arr);
    for (int i = 0; i < n; i++) {
        while (!q.empty () && arr[q.back ()] > arr[i])
            q.pop_back ();
        q.push_back (i);
        if (i - q.front () >= k && q.front () == i - k) {
            q.pop_front ();
        }
        printf ("[%d %d] = arr[%d] = %d\n", max (i - k + 1, 0), i,
                q.front (), arr[q.front ()]);
    }
    return 0;
}
