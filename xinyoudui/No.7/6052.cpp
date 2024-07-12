#include <bits/stdc++.h>
using namespace std;
char a[550], b[550];
int main() {
    scanf("%s", a);
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (a[i] == 'A') b[i] = 'T';
        else if (a[i] == 'T') b[i] = 'A';
        else if (a[i] == 'G') b[i] = 'C';
        else if (a[i] == 'C') b[i] = 'G';
    }
    printf("%s\n", b);
    return 0;
}