#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int C[MAX_N + 5] = {0}; // NOTE : 每条边的权值
int fa[MAX_N + 5] = {0}; // NOTE : 每个节点的父节点
int vis[MAX_N + 5] = {0}; // NOTE : 是否合并
int cnt[MAX_N + 5] = {0}; // NOTE : 每个节点蕴含的节点数量
double w[MAX_N + 5] = {0}; // NOTE : 用于比较的权值
int n,r;
long long ans = 0;
int find_x() { // NOTE : 寻找"x"
    int x = -1;
    for(int i = 1;i <= n;i++) {
        if(i == r || vis[i] == 1) continue;
        if(x == -1 || w[x] < w[i]) x = i;
    }
    return x;
}
int find_father(int x) { // NOTE : 寻找x节点的父节点
    if(vis[fa[x]]) return find_father(fa[x]);
    return fa[x];
}
int main() {
    scanf("%d%d",&n,&r);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&C[i]);
        ans += C[i]; // NOTE : 公式里的“根节点”
        fa[i] = i;
        w[i] = C[i];
        cnt[i] = 1;
    }
    for(int i = 1,a,b;i < n;i++) {
        scanf("%d%d",&a,&b);
        fa[b] = a;
    }
    for(int i = 1;i < n;i++) { // NOTE : 染色
        int x = find_x();
        int father_x = find_father(x);
        ans += cnt[father_x] * C[x];
        C[father_x] += C[x];
        cnt[father_x] += cnt[x];
        w[father_x] = 1.0 * C[father_x] / cnt[father_x];
        vis[x] = 1;
    }
    printf("%lld\n",ans);
    return 0;
}