#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int n,m;
int arr[MAX_N + 5];
long long sum[MAX_N + 5] = {0};
bool check(long long a) { // NOTE : 检查
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + arr[i] - a;
    long long minnum = 0;
    for(int i = m;i <= n;i++) {
        minnum = min(minnum,sum[i - m]);
        if(sum[i] - minnum >= 0) return true;
    }
    return false;

}
long long solve(long long maxnum) { // NOTE : 二分查找
    long long l = 0,r = maxnum,mid;
    while(l < r) {
        mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    scanf("%d%d",&n,&m);
    long long maxnum = 0;
    for(int i = 1,x;i <= n;i++) { // NOTE : 输入数据
        scanf("%d",&x);
        arr[i] = x * 1000;
        maxnum = max(maxnum,static_cast<long long>(arr[i]));
    }
    printf("%lld\n",solve(maxnum)); // NOTE : 输出结果
    return 0;
}