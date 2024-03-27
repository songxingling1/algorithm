#include <bits/stdc++.h>
using namespace std;
int ans[15];
int n;
void print(int cnt) {
    for(int i = 1;i <= cnt;i++) {
        if(i != 1) printf(" ");
        printf("%d",ans[i]);
    }
}
void solve(int step,int top) {
    if(top == n + 1) {
        return;
    }
    print(step);
    for(int i = top + 1;i <= n;i++) {
        ans[step] = i;
        solve(step + 1,i);
    }
}
int main() {
    scanf("%d",&n);
}