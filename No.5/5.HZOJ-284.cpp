#include <bits/stdc++.h>
using namespace std;
struct thing {
    int d, p;
    thing(int _d, int _p)
    : d(_d)
    , p(_p) {}
    thing() = default;
} arr[10005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, a, b; i <= n; i++) {
        scanf("%d%d", &b, &a);
        arr[i].d = a;
        arr[i].p = b;
    }
    sort(arr + 1,
         arr + 1 + n,
         [](const thing &i, const thing &j) {
             return i.d < j.d;
         });
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(arr[i].p);
        } else {
            if (arr[i].p >= *s.begin()) {
                s.erase(s.begin());
                s.insert(arr[i].p);
            }
        }
    }
    int ans = 0;
    for (int i : s) {
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}