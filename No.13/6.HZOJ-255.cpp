#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
struct qujian { // NOTE : 区间
    double l,r;
} arr[MAX_N + 5];
int main() {
    int n;
    double r,x,y,delta,pos;
    scanf("%d%lf",&n,&r); // NOTE : 输入
    for(int i = 1;i <= n;i++) {
        scanf("%lf%lf",&x,&y);
        if(y > r) { // NOTE : 特判
            printf("-1\n");
            return 0;
        }
        delta = sqrt(r * r - y * y); // NOTE : 处理区间
        arr[i].l = x - delta;
        arr[i].r = x + delta;
    }
    sort(arr + 1,arr + n + 1,[](const qujian &i,const qujian &j)->bool{
        return i.r < j.r;
    }); // NOTE : 排序
    int ans = 1; // NOTE : 安装雷达数
    pos = arr[1].r; // 最后一个雷达的x坐标
    for(int i = 2;i <= n;i++) { // 在每一个区间内安装雷达
        if(pos < arr[i].l) { // 如果当前雷达探测不到这个区间
            ans++; //新安装一个雷达
            pos = arr[i].r;
        }
    }
    printf("%d\n",ans);
    return 0;
}