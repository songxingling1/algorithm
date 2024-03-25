#include <bits/stdc++.h>
using namespace std;
char num[250];
int nxt[250];
int pre[250];
void del() {
    int p = nxt[0];
    while (true) {
        if (num[p] <= num[nxt[p]]) {
            p = nxt[p];
            continue;
        }
        nxt[pre[p]] = nxt[p];
        pre[nxt[p]] = pre[p];
        break;
    }
    while (num[nxt[0]] == '0') {
        nxt[0] = nxt[nxt[0]];
        pre[nxt[0]] = 0;
    }
}
int main() {
    scanf("%s", num + 1);
    int count, len;
    len = strlen(num + 1);
    scanf("%d", &count);
    for (int i = 0; i <= len; i++) {
        nxt[i] = i + 1;
        pre[i + 1] = i;
    }
    for (int i = 0; i < count; i++) {
        del();
    }
    for (int i = nxt[0]; num[i] != '\0'; i = nxt[i]) {
        printf("%c", num[i]);
    }
    puts("");
    return 0;
}