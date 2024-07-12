#include <bits/stdc++.h>
using namespace std;
struct stu {
    string name;
    int tot;
    int c, m;
    int id;
} arr[105];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].name >> arr[i].c >> arr[i].m;
        arr[i].tot = arr[i].c + arr[i].m;
        arr[i].id = i;
    }
    sort(arr + 1, arr + 1 + n, [](const stu &i, const stu &j) -> bool {
        if (i.tot != j.tot) return i.tot > j.tot;
        return i.id < j.id;
    });
    for (int i = 1; i <= n; i++) {
        cout << arr[i].name << " " << arr[i].c << " " << arr[i].m << " " << arr[i].tot << endl;
    }
    return 0;
}