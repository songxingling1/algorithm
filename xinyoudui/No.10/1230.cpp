#include <bits/stdc++.h>
using namespace std;
int arr[1005];
void insert_sort(int n) {
    for (int i = 2; i <= n; i++) {
        int j = i;
        while (j > 1 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", arr + i);
    insert_sort(n);
    for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
    return 0;
}