#include <bits/stdc++.h>
#define MAX_N 100
#define H(i) books[i].height
#define W(i) books[i].width
#define J(i,j) abs(W(i) - W(j))
using namespace std;
int dp[MAX_N + 5][MAX_N + 5];
struct Book {
    int height,width;
} books[MAX_N + 5];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&H(i),&W(i));
    }
    sort(books + 1,books + n + 1,[](const Book &i,const Book &j)->bool{
        return i.height < j.height;
    });
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n - k;j++) {
            if(j == 1) {
                continue;
            }
            if(i < j) {
                dp[i][j] = 0x3f3f3f3f;
                continue;
            }
            dp[i][j] = 0x3f3f3f3f;
            for(int k = 1;k < i;k++) {
                dp[i][j] = min(dp[i][j],dp[k][j - 1] + J(k,i));
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i = n - k;i <= n;i++) {
        ans = min(ans,dp[i][n - k]);
    }
    printf("%d\n",ans);
    return 0;
}