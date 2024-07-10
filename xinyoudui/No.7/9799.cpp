#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char s[105], maxs[105], mins[105];
int main() {
    int maxl = 0, minl = 105, l;
    while (scanf("%[^,.\x20]", s) != EOF) {
        l = strlen(s);
        if(l == 0) continue;
#ifdef DEBUG
            printf("Found : %s\n",s);
#endif
        if (l > maxl) {
            maxl = l;
            strcpy(maxs, s);
        }
        if (l < minl) {
            minl = l;
            strcpy(mins, s);
        }
        getchar();
    }
    printf("%s\n%s\n", maxs, mins);
    return 0;
}