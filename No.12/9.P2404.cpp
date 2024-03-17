#include <bits/stdc++.h>
#define MAX_N 8
using namespace std;
int n;
int ans[MAX_N + 5];
void print(int n) {
    if (n == 2)
        return;
    for (int i = 1; i < n; i++) {
        if (i != 1)
            printf("+");
        printf("%d", ans[i]);
    }
    puts("");
}
void dfs(int top, int yu, int step) {
    if (yu == 0)
        print(step);
    for (int i = top; 2 * i <= yu; i++) {
        ans[step] = i;
        dfs(i, yu - i, step + 1);
    }
    ans[step] = yu;
    print(step + 1);
}
int main() {
    scanf("%d", &n);
    dfs(1, n, 1);
    return 0;
}