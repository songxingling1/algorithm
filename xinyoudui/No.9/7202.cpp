#include <bits/stdc++.h>
using namespace std;
struct bb {
    int a, b, c;
    string n;
};
struct aa {
    int a, b;
    string c;
    bb d;
} arr[100005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].d.a >> arr[i].d.b >> arr[i].d.c >> arr[i].d.n;
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << " " <<
                arr[i].d.b << " " << arr[i].d.c << " " << arr[i].d.n << endl;
    }
    return 0;
}