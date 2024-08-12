#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL ans[65];
LL h[65][65];
LL g[65][65];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1,u,v;i <= m;i++) {
        scanf("%d%d",&u,&v);
        h[u][v] = h[v][u] = 1;
    }
    for(int v = 1;v <= n;v++) {
        memset(g,0,sizeof(g));
        g[n + 1][v] = g[n + 1][n + 1] = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                g[i][j] = h[i][j];
            }
        }
        for(int i = 1;i <= n;i++) {
            int cur = -1;
            for (int j = i; j <= n + 1; j++) {
                if (g[j][i] == 1) {
                    cur = j;
                }
            }
            if(cur == -1) continue;
            swap(g[cur],g[i]);
            for(int j = 1;j <= n + 1;j++) {
                if(i != j && g[j][i]) {
                    for(int k = 1;k <= n + 1;k++) {
                        g[j][k] ^= g[i][k];
                    }
                }
            }
        }
        for(int i = 1;i <= n + 1;i++) {
            int cnt = 0;
            for(int j = 1;j <= n;j++) {
                if(g[i][j]) cnt++;
            }
            if(cnt == 0 && g[i][n + 1]) {
                printf("No\n");
                return 0;
            } else if(g[i][n + 1]) {
                ans[i] += g[i][n + 1] << (v - 1);
            }
        }
    }
    printf("Yes\n");
    for(int i = 1;i <= n;i++) {
        printf("%lld ",ans[i]);
    }
    puts("");
    return 0;
}