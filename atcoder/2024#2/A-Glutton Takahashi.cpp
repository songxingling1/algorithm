#include <bits/stdc++.h>
using namespace std;
string s[105];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int flag = 0;
    for (int i = 2; i <= n; i++) {
        if (flag) {
            printf("No\n");
            return 0;
        }
        if (s[i] == "sweet" && s[i - 1] == "sweet") {
            flag = 1;
        }
    }
    printf("Yes\n");
    return 0;
}