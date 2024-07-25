#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
    int n, minn = 0x3f3f3f3f, ans = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        if (minn > arr[i]) minn = arr[i];
    }
    int flag = 1;
    for (int j = 0; j < n; j++) {
        if (arr[j] != minn) continue;
        flag = 1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[(j + i) % n] > arr[(j + i + 1) % n]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans = j;
            break;
        }
    }
    printf("%d\n", n - ans);
    return 0;
}