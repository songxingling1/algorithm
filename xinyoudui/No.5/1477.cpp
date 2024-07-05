#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int flag[MAX_N + 5];
int main() {
    int L, M;
    scanf("%d%d", &L, &M);
    for (int i = 1, l, r; i <= M; i++) {
        scanf("%d%d", &l, &r);
        for (int j = l; j <= r; j++) {
            flag[j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= L; i++) {
        if (!flag[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}