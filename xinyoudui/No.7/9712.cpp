#include <bits/stdc++.h>
using namespace std;
char s[300];
int main() {
    scanf("%[^\n]", s);
    int len = strlen(s), ans = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') ans++;
    }
    printf("%d\n", ans);
    return 0;
}