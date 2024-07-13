#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[100005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, a, b; i <= n; i++) {
        scanf("%d%d", &a, &b);
        arr[i] = make_pair(a, b);
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", arr[i].first, arr[i].second);
    }
    return 0;
}