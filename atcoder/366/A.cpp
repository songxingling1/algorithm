#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t,a;
    scanf("%d%d%d",&n,&t,&a);
    if(n - t - a + min(t,a) < max(t,a)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}