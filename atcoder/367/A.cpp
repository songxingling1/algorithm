#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(b >= c) {
        c += 24;
    }
    if((b <= a && a <= c) | (b <= a + 24 && a + 24 <= c)) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}