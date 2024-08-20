#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
using LL = long long;
int n, m;
LL a[100000];
LL c[2][100005];
void add(int k, int i, LL v, int n) {
    while (i <= n) c[k][i] += v, i += lowbit(i);
}
LL query(int k, int i) {
    LL sum = 0;
    while (i) {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}
LL Q(int k) {
    LL a1 = query(0, k);
    LL a2 = query(1, k);
    return (k + 1) * a1 - a2;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        add(0, i, a[i] - a[i - 1], n);
        add(1, i, i * (a[i] - a[i - 1]), n);
    }
    for (int i = 1; i <= m; i++) {
        char ch;
        cin >> ch;
        if (ch == 'C') {
            int a, b;
            LL c;
            cin >> a >> b >> c;
            add(0, a, c, n);
            add(0, b + 1, -c, n);
            add(1, a, a * c, n);
            add(1, b + 1, -(b + 1) * c, n);
        } else {
            int a, b;
            cin >> a >> b;
            cout << Q(b) - Q(a - 1) << endl;
        }
    }
    return 0;
}