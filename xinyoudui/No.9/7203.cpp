#include <bits/stdc++.h>
using namespace std;
struct s {
    int a[35], b[35];
    int len;
} arr[100005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i].len);
        for (int j = 1; j <= arr[i].len; j++) {
            scanf("%d%d",&arr[i].a[j],&arr[i].b[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= arr[i].len; j++) {
            if (j % 2 == 0) {
                printf("%d\n",min(arr[i].a[j],arr[i].b[j]));
            } else {
                printf("%d\n",max(arr[i].a[j],arr[i].b[j]));
            }
        }
    }
    return 0;
}