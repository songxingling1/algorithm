#include <bits/stdc++.h>
using namespace std;
int shop[100010];
int main() {
    int n;
    scanf("%d\n",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&shop[i]);
    }
    sort(shop + 1,shop + n + 1);
    int i = 1,j = n,ans = 0;
    while(i < j) {
        ans += shop[j] - shop[i];
        i++;
        j--;
    }
    printf("%d\n",ans);
    return 0;
}