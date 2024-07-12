#include <bits/stdc++.h>
using namespace std;
struct s {
    int a,b,c;
} arr[100000];
void Sort(s &x) {
    if (x.a > x.b) swap(x.a, x.b);
    if (x.b > x.c) swap(x.b, x.c);
    if (x.a > x.b) swap(x.a, x.b);
}
void Swap(s &x, int type) {
    switch (type) {
        case 1:
            swap(x.a, x.b);
            break;
        case 2:
            swap(x.b, x.c);
            break;
        case 3:
            swap(x.a, x.c);
            break;
    }
}
int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int Clac(s x) {
    int a = gcd(x.a, x.b), b = gcd(x.b, x.c);
    return a * b % 100000 + x.a + x.b + x.c;
}
int main() {
    int n, m;
    string op;
    int t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
        scanf("%d", &m);
        for (int j = 1; j <= m; j++) {
            cin >> op;
            if (op == "Sw") cin >> t;
            if (op == "S") Sort(arr[i]);
            else if (op == "Sw") Swap(arr[i], t);
            else if(op == "C") cout << Clac(arr[i]) << endl;
        }
    }
    return 0;
}