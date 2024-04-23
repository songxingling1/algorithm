#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
struct dat { // NOTE : 机器和任务存储结构
    int x,y;
} ta[MAX_N],ma[MAX_N];
int cnt[105];
bool cmp(const dat &i,const dat &j) { // NOTE : 排序方案
    if(i.x != j.x) return i.x > j.x;
    return i.y > j.y;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m); // NOTE : 输入
    long long ans = 0,task_cnt = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&ma[i].x,&ma[i].y);
    }
    for(int i = 1;i <= m;i++) {
        scanf("%d%d",&ta[i].x,&ta[i].y);
    }
    sort(ma + 1,ma + 1 + n,cmp); // NOTE : 排序
    sort(ta + 1,ta + 1 + m,cmp);
    for(int i = 1,j = 1;i <= m;i++) { // NOTE : 分配任务
        while(j <= n && ma[j].x >= ta[i].x) { // NOTE : 维护时间维度上可以处理的机器
            cnt[ma[j].y]++;
            j++;
        }
        for(int y = ta[i].y;y <= 100;y++) { // NOTE : 选择机器
            if(cnt[y] == 0) continue;
            cnt[y]--;
            ans += 500 * ta[i].x + 2 * ta[i].y;
            task_cnt++;
            break;
        }
    }
    printf("%lld %lld\n",task_cnt,ans); // NOTE : 输出
    return 0;
}