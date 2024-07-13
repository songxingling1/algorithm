#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
    unsigned long long a1, a2, k, tmp;
    scanf("%lld%lld%lld", &a1, &a2, &k);
    string s = to_string(a1) + to_string(a2);
    while (s.size() < k) {
        tmp = a1 + a2;
        a1 = a2;
        a2 = tmp;
        s += to_string(tmp);
    }
    printf("%c\n", s[k - 1]);
    return 0;
}