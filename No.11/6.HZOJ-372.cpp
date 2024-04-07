#include <bits/stdc++.h>
#define MAX_N 500000
using namespace std;
int arra[MAX_N + 5],arrb[MAX_N + 5];
int main() {
    int n;// NOTE : 输入
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&arra[i]);
    for(int i = 1;i <= n;i++) scanf("%d",&arrb[i]);
    stack<int> sta,stb; // NOTE : 处理
    int i = 1;
    for(;i <= n;i++) {
        while(!sta.empty() && arra[sta.top()] >= arra[i]) sta.pop();
        while(!stb.empty() && arrb[stb.top()] >= arrb[i]) stb.pop();
        sta.push(i);
        stb.push(i);
        if(sta.size() != stb.size()) {
            break;
        }
    }
    printf("%d\n",i - 1); //NOTE : 输出
    return 0;
}