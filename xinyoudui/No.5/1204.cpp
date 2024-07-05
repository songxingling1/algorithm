#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        m[t]++;
    }
    for (auto i : m) {
        if (i.second > n / 2) {
            printf("%d\n", i.first);
            return 0;
        }
    }
    return 0;
}