#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 1) {
        printf("-1\n");
        return 0;
    }
    vector<int> arr;
    while (n) {
        arr.push_back(n & -n);
        n -= n & -n;
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}