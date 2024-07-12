#include <bits/stdc++.h>
using namespace std;
int n = 1,last = 0;
int generate() {
    last += 2;
    n++;
    return last;
}
int main() {
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        printf("%d\n",generate());
    }
    return 0;
}