#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans = (ans + 1) * 2;
    }
    printf("%d\n", ans);
    return 0;
}