#include <bits/stdc++.h>
using namespace std;
int a[505];
int main() {
    int n, k = 1;
    int cnt = 0, sum = 0;
    scanf("%d", &n);
    while (scanf("%d", a + k) != EOF) {
        k++;
    }
    for (int i = 1; i < k; i++) {
        if (sum + a[i] > n) {
            cnt++;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i < k; i++) printf("%.1f ", a[i] * 1.2);
    puts("");
    return 0;
}