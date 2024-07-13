#include <bits/stdc++.h>
using namespace std;
struct Class {
    int cnt;
    int id;
} arr[1005];
int main() {
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        arr[t].cnt++;
        arr[t].id = t;
    }
    sort(arr + 1, arr + 1000, [](const Class &i, const Class &j) -> bool {
        if (i.cnt != j.cnt) return i.cnt > j.cnt;
        return i.id < j.id;
    });
    for (int i = 1; arr[i].cnt != 0; i++) {
        if (flag) printf("->");
        printf("%d", arr[i].id);
        flag = 1;
    }
    puts("");
    return 0;
}