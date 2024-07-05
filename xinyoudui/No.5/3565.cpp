#include <bits/stdc++.h>
#define MAX_N 10
using namespace std;
int cnt[MAX_N + 5], pos[MAX_N + 5];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        cnt[t]++;
        if (pos[t] == 0) pos[t] = i;
    }
    int maxn = 0;
    for (int i = 0; i <= 10; i++) {
        if (cnt[maxn] == cnt[i] && pos[maxn] > pos[i]) maxn = i;
        if (cnt[maxn] < cnt[i]) maxn = i;
    }
    printf("%d\n", maxn);
    return 0;
}