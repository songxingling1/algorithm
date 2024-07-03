#include <bits/stdc++.h>
using namespace std;
int check(int x) {
    vector<int> a;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    for (int i = 0, j = a.size() - 1; i < j; i++, j--) {
        if (a[i] != a[j]) return 0;
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}