#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int cnt[N], t[N];
vector<int> a[N];
int res;
void add(int g) {
    res += (++cnt[g] == 1);
}
void del(int g) {
    res -= (--cnt[g] == 0);
}
int main() {
    int n, l = 1;
    scanf("%d", &n);
    for (int i = 1, k; i <= n; i++) {
        scanf("%d%d", &t[i], &k);
        for (int j = 1, tmp; j <= k; j++) {
            scanf("%d", &tmp);
            add(tmp);
            a[i].push_back(tmp);
        }
        while (t[i] - 86400 >= t[l]) {
            for (int j = 1; j < a[l].size(); j++) {
                del(a[l][i]);
            }
            ++l;
        }
        printf("%d\n", res);
    }
    return 0;
}