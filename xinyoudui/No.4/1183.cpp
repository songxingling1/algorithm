#include <bits/stdc++.h>
using namespace std;
void solve(int x) {
    string s;
    int tmp = 0, flag = 0, i = 2, b = x;
    while (x != 1) {
        if (x % i != 0) {
            if (tmp == 0) {
                i++;
                continue;
            }
            if (flag) s += '*';
            s += to_string(i);
            if (tmp > 1) s += '^' + to_string(tmp);
            flag = 1;
            tmp = 0;
            i++;
            continue;
        }
        x /= i;
        tmp++;
    }
    if (flag) s += '*';
    s += to_string(i);
    if (tmp > 1) s += '^' + to_string(tmp);
    printf("%d=%s\n", b, s.c_str());
}
int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}