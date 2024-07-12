#include <bits/stdc++.h>
using namespace std;
char a[60];
int main() {
    scanf("%s", a);
    int last = strlen(a) - 1;
    if (a[last - 1] == 'e' && a[last] == 'r') {
        a[last - 1] = '\0';
    } else if (a[last - 1] == 'l' && a[last] == 'y') {
        a[last - 1] = '\0';
    } else if (a[last - 2] == 'i' && a[last - 1] == 'n' && a[last] == 'g') {
        a[last - 2] = '\0';
    }
    printf("%s\n", a);
    return 0;
}