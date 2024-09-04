#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b) printf("1\n");
    else if ((a + b) % 2 == 1) printf("2\n");
    else printf("3\n");
    return 0;
}