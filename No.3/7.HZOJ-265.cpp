#include <bits/stdc++.h>
#define MAX_S 10000
using namespace std;
char s[MAX_S + 5];
int match[MAX_S + 5]; //match[i] == 0 :没有合法匹配       match[i] != 0 :存储匹配括号位置
stack<int> sta;
int main() {
    s[0] = 'h';
    scanf("%s",s + 1);
    for (int i = 1; s[i]; i++)
    {
        switch(s[i]) {
            case '(':
            case '[':
            case '{':
                sta.push(i);
                break;
            case ')':
                if(!sta.empty() && s[sta.top()] == '(') {
                    match[sta.top()] = i;
                    sta.pop();
                } else {
                    sta.push(i);
                }
                break;
            case ']':
                if(!sta.empty() && s[sta.top()] == '[') {
                    match[sta.top()] = i;
                    sta.pop();
                } else {
                    sta.push(i);
                }
                break;
            case '}':
                if(!sta.empty() && s[sta.top()] == '{') {
                    match[sta.top()] = i;
                    sta.pop();
                } else {
                    sta.push(i);
                }
                break;
        }
    }
    int temp_ans = 0,ans = 0;
    int i = 1;
    while(s[i]) {
        if(match[i]) {
            temp_ans += match[i] - i + 1;
            i = match[i] + 1;
        } else {
            i++;
            temp_ans = 0;
        }
        ans = max(temp_ans,ans);
    }
    printf("%d\n",ans);
    return 0;
}
