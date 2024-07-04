#include <bits/stdc++.h>
#include <string>
using namespace std;
void solve(int x) {
    string s;
    int i = 2, tmp = 0, flag = 0;
    while (x != 1) {
        if (x % i != 0) {
            if (tmp == 0) {
                i++;
                continue;
            }
            if (flag) s += '*';
            if (tmp == 1) s += to_string(i);
            else s += to_string(i) + '^' + to_string(tmp);
            tmp = 0;
            flag = 1;
            i++;
            continue;
        }
        x /= i;
        tmp++;
    }
    if (flag) s += '*';
    if (tmp == 1) s += to_string(i);
    else if (tmp > 1) s += to_string(i) + '^' + to_string(tmp);
    cout << s << endl;
}
int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}