#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int cnt[MAX_N + 5];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        cnt[t]++;
    }
    int maxn = 0;
    for (int i = 0; i <= MAX_N; i++) {
        if (cnt[maxn] < cnt[i]) maxn = i;
    }
    printf("%d\n", maxn);
    return 0;
}