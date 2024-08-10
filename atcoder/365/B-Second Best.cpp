#include <bits/stdc++.h>
using namespace std;
int a[105];
int ind[105];
bool cmp(int i, int j) {
    return a[i] > a[j];
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        ind[i] = i;
    }
    sort(ind + 1, ind + 1 + n, cmp);
    printf("%d\n", ind[2]);
    return 0;
}