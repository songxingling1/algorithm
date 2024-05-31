#include <bits/stdc++.h>
#define MAX_N 100000
#define P(a) ((a) * (a))
#define DIS(x1x,y1y,x2x,y2y) P(x1x - x2x) + P(y1y - y2y)
int x[MAX_N + 5],y[MAX_N + 5],ind[MAX_N + 5];
int dis[MAX_N + 5];
int n,x1,yy1,x2,y2;
using namespace std;
int main() {
    scanf("%d%d%d%d%d",&x1,&yy1,&x2,&y2,&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        ind[i] = i;
    }
    sort(ind + 1,ind + 1 + n,[](int i,int j)->bool{
        return DIS(x[i],y[i],x1,yy1) < DIS(x[j],y[j],x1,yy1);
    });
    for(int i = n;i >= 1;i--) {
        dis[i] = DIS(x[ind[i]],y[ind[i]],x2,y2);
        dis[i] = max(dis[i + 1],dis[i]);
    }
    int ans = dis[1];
    for(int i = 1;i <= n;i++) {
        ans = min(ans,DIS(x[ind[i]],y[ind[i]],x1,yy1) + dis[i + 1]);
    }
    printf("%d\n",ans);
    return 0;
}