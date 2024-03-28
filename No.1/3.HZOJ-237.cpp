#include <bits/stdc++.h>
using namespace std;
int n;
int ans[11];
bool vis[11]; // 用数组记录数字是否使用过
void print() {
    for(int i = 1;i <= n;i++) {
        if(i != 1) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}
void solve(int step) {
    if(step == n) { // 若n个数字全部放置完毕
        print();    // 输出
        return;
    }
    for(int i = 1;i <= n;i++) {
//                      ^
//               从小往大遍历，保证字典序
        if(vis[i]) continue;
        ans[step + 1] = i;
        vis[i] = true;
        solve(step + 1);
        vis[i] = false;
    }
}
int main() {
    scanf("%d",&n);
    solve(0);
    return 0;
}