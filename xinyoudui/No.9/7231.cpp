#include <bits/stdc++.h>
using namespace std;
struct s {
    string name;
    int ch,ma,en,tot;
} arr[1005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].name >> arr[i].ch >> arr[i].ma >> arr[i].en;
        arr[i].tot = arr[i].ch + arr[i].ma + arr[i].en;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(arr[i].ch - arr[j].ch) <= 5 && abs(arr[i].ma - arr[j].ma) <= 5 && abs(arr[i].en - arr[j].en) <= 5 &&
                abs(arr[i].tot - arr[j].tot) <= 10) {
                cout << arr[i].name << " " << arr[j].name << endl;
            }
        }
    }
    return 0;
}