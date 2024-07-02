#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char c;
    scanf("%d%c",&n,&c);
    int ans = 8;
    if(n > 1000) {
        ans += ceil((n - 1000) / 500.0) * 4;
    }
    if(c == 'y') {
        ans += 5;
    }
    printf("%d\n",ans);
    return 0;
}