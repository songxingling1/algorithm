#include <bits/stdc++.h>
using namespace std;
int arr[1005];
void insert_sort(int n) {
    for (int i = 1; i < n; i++) {
        int ind = i;
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
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