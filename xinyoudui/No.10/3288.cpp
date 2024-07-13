#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
    int n, minn = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        if (arr[minn] > arr[i]) minn = i;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[(minn + i) % n] > arr[(minn + i + 1) % n]) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", n - minn);
    return 0;
}