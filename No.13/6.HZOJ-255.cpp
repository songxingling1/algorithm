#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
struct qujian {
    double l,r;
} arr[MAX_N + 5];
int main() {
    int n;
    double d;
    scanf("%d%lf",&n,&d);
    int ans;
    double pos,x,y;
    for(int i = 1;i <= n;i++) { // NOTE : 输入和完成数据转换
        scanf("%lf%lf",&x,&y);
        if(y > d) {
            printf("-1\n");
            return 0;
        }
        double delta = sqrt(d * d - y * y);
        arr[i].l = x - delta;
        arr[i].r = x + delta;
    }
    sort(arr + 1,arr + 1 + n,[](const qujian &i,const qujian &j)->bool{
        return i.r < j.r; // NOTE : 按右顶点排序
    });
    pos = arr[1].r,ans = 1;
    for(int i = 2;i <= n;i++) { // NOTE : 安装雷达
        if(arr[i].l > pos) {
            ans++;
            pos = arr[i].r;
        }
    }
    printf("%d\n",ans);
    return 0;
}