#include <bits/stdc++.h>
using namespace std;
char s[100005];
int solve(int n) {
    if (n % 2 == 1) return n;
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) return n;
        i++;
        j--;
    }
    return solve(n / 2);
}
int main() {
    scanf("%s", s);
    printf("%d\n", solve(strlen(s)));
    return 0;
}