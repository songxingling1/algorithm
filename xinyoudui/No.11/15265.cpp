#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
struct jilu {
    int day, h;
    string n;
} a[105];
struct cow {
    string n;
    int h = 7;
} b[105];
bool cmp(const cow &i, const cow &j) {
    if (i.h != j.h) return i.h > j.h;
    return i.n < j.n;
}
int main() {
    int n;
    char ch;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].day >> a[i].n >> ch >> a[i].h;
        if (ch == '-') a[i].h *= -1;
    }
    sort(a + 1, a + 1 + n, [](const jilu &i, const jilu &j) -> bool { return i.day < j.day; });
    int cnt = 0;
    unordered_map<string, int> m;
    vector<string> v;
    int maxx, j;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (m.find(a[i].n) != m.end()) {
            b[m[a[i].n]].h += a[i].h;
        } else {
            m[a[i].n] = ++cnt;
            b[cnt].n = a[i].n;
        }
        sort(b + 1, b + 1 + cnt, cmp);
        maxx = b[1].h;
        j = 1;
        while (j <= cnt && b[j].h == maxx) {
            if (v[j] != b[j].n) {
                ;
            }
        }
    }
    return 0;
}