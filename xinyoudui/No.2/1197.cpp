#include <bits/stdc++.h>
using namespace std;
int main() {
    int base,above,total;
    scanf("%d%d%d",&base,&above,&total);
    if(total < base) {
        printf("0\n");
        return 0;
    }
    int n = total / base;
    int ans = n * 3;
    ans += (total - n * base) / above;
    printf("%d\n",max(ans,3 + (total - base) / above));
    return 0;
}