#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
struct Dat {
    int a,b;
} task[MAX_N + 5],mach[MAX_N + 5];
int cnt[105] = {0};
bool cmp(const Dat &i,const Dat &j) {
    if(i.a != j.a) return i.a > j.a;
    return i.b > j.b;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&mach[i].a,&mach[i].b);
    }
    for(int i = 1;i <= m;i++) {
        scanf("%d%d",&task[i].a,&task[i].b);
    }
    sort(task + 1,task + m + 1,cmp); // NOTE : 排序
    sort(mach + 1,mach + 1 + n,cmp); // NOTE : 排序
    long long ans = 0,num = 0;
    for(int i = 1,j = 1;i <= m;i++) {
        while(j <= n && mach[j].a >= task[i].a) {
            cnt[mach[j].b]++;
            j++;
        }
        for(int k = task[i].b;k <= 100;k++) {
            if(cnt[k] == 0) continue;
            cnt[k]--;
            ans += 500 * task[i].a + 2 * task[i].b;
            num++;
            break;
        }
    }
    printf("%lld %lld\n",num,ans);
    return 0;

}