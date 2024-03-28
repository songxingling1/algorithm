#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans[15];
void print() {
    for(int i = 1;i <= m;i++) {
        if(i != 1) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}
void solve(int step,int top) {
    if(step == m) { //当选满m个数时
        print();    //输出
        return;
    }
    if(top == n + 1) {
        return;
    }
    for(int i = top;i <= n;i++) {
//            ^           ^
//            |    从小往大遍历，保证字典序
// 每一次从上一个数+1开始遍历，保证每一个数都比前面的数大。
        ans[step + 1] = i;
        solve(step + 1,i + 1);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    solve(0,1);
    return 0;
}
