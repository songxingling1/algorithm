#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
char str[MAX_N + 5];
struct ch {
    bool isB;
    char c;
    int size;
    ch(bool type,char d,int s):isB(type),c(d),size(s) {}
    ch() = default;
};
int solve() {
    stack<ch> sta;
    int len = strlen(str);
    sta.emplace(false,'\0',0);
    sta.emplace(false,str[0],0);
    ch tmp,tmp2;
    for(int i = 1;i < len;i++) {
        tmp = sta.top();
        if(tmp.isB) {
            sta.pop();
            tmp2 = sta.top();
            if(tmp2.isB == false &&
              ((tmp2.c == '(' && str[i] == ')') ||
              (tmp2.c == '[' && str[i] == ']') ||
              (tmp2.c == '{' && str[i] == '}'))) {
                sta.pop();
                if(sta.top().isB) {
                    tmp.size += sta.top().size;
                    sta.pop();
                }
                sta.emplace(true,'\0',tmp.size + 2);
            } else {
                sta.push(tmp);
                sta.emplace(false,str[i],0);
            }
        } else {
            if(((tmp.c == '(' && str[i] == ')') ||
                (tmp.c == '[' && str[i] == ']') ||
                (tmp.c == '{' && str[i] == '}'))) {
                sta.pop();
                if(sta.top().isB) {
                    tmp.size += sta.top().size;
                    sta.pop();
                }
                sta.emplace(true,'\0',tmp.size + 2);
            } else {
                sta.emplace(false,str[i],0);
            }
        }
    }
    int ans = 0;
    while(!sta.empty()) {
        tmp = sta.top();
        if(tmp.isB) ans = max(ans,tmp.size);
        sta.pop();
    }
    return ans;
}
int main() {
    scanf("%s",str);
    printf("%d\n",solve());
    return 0;
}