#include <bits/stdc++.h>
using namespace std;
int arr[1005];
void bubble_sort(int n) {
    bool flag;
    for (int i = n - 1; i >= 2; i--) {
        flag = true;
        for (int j = 1; j < i; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            flag = false;
        }
        if (flag) break;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", arr + i);
    bubble_sort(n);
    for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
    return 0;
}