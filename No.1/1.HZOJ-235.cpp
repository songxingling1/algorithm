#include <bits/stdc++.h>
using namespace std;
int ans[15];
int n;
void print(int cnt) {
    for(int i = 1;i <= cnt;i++) {
        if(i != 1) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}
void solve(int step,int top) {
    if(top == n + 1) {
        return;
    }
    if(top != 0) print(step - 1);
    for(int i = top + 1;i <= n;i++) {
//             ^             ^
//             |      从小往大遍历，保证字典序
// 每一次从上一个数+1开始遍历，保证每一个数都比前面的数大。
        ans[step] = i;
        solve(step + 1,i);
    }
}
int main() {
    scanf("%d",&n);
    solve(1,0);
    return 0;
}