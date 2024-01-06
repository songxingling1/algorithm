#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
char s[MAX_N + 5];//字符串
int m[MAX_N + 5] = {0}; //权
int judge(int pos) { //判断运算符层级
    if(s[pos] == '-' && (s[pos - 1] == '(' || pos == 1 || (!isdigit(s[pos - 1]))) && s[pos - 1] != ')') return 4;
    char c = s[pos];
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 4;
}
int qpow(int a,int b) { //快速幂
    int ans = 1;
    while(b) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void str() { //计算权值
    int isK = 0;
    int size = strlen(s);
    /**********************   第一部分：遍历字符串   ***************************/
    for(int i = 1;i < size;i++) {
        if(s[i] == '(') isK += 100; //bug1:权值没有考虑到有多重括号的式子 (isk = true)
        m[i] = judge(i) + isK;
        if(s[i] == ')' && isK != 0) isK -= 100;//bug1:权值没有考虑到有多重括号的式子 (isk = false)
    }
}
int isNumber(int begin,int end) { //判断是否为数字：不是返回-1             是返回数字的值
    int ans = 0;
    int dr = 0;
    if(!(isdigit(s[begin]) || s[begin] == '-') && s[begin] != '(' && s[begin] != ')') return -1;
    if(s[begin] == '-') dr = -1;
    if(isdigit(s[begin])) ans = (int)s[begin] - '0'; //bug4:没有考虑到第一位是数字的情况 (delete)
    for(int i = begin + 1;i <= end;i++) {
        if(s[i] == '(' || s[i] == ')') continue;
        if(!isdigit(s[i]) && !(dr == 0 && s[i] == '-')) return -1; //bug3:没有考虑到'-'不在第一位的情况 (if(!isdigit(s[i])) return -1;)
        if(dr == 0 && s[i] == '-') dr = -1;
        else ans = ans * 10 + int(s[i] - '0');
    }
    if(dr == -1) ans *= -1;
    return ans;
}
int solve(int __begin,int __end) { //主要解决方案
    /*******************   边界   ******************/
    int nums = isNumber(__begin,__end);
    if(nums != -1) return nums;
    /**********************   第一部分：遍历字符串   ***************************/
    //在79行执行过了！！！
    /***************************   第二部分：取最小值    ***************************************/
    int pos = 0,num = 0x3f3f3f3f;
    for(int i = __begin;i <= __end;i++) {
        if(s[i] == '(' || s[i] == ')') continue;
        if(num >= m[i]) { //bug2:没有从左往右计算 (num > m[i])
            num = m[i];
            pos = i;
        }
    }
    /*********************    第三部分：分割    ***********************/
    int a = solve(__begin,pos - 1);
    int b = solve(pos + 1,__end);
    /*********************   第四部分：计算   ***********************/
    switch(s[pos]) {
        case '^':return qpow(a,b);
        case '+':return a + b;
        case '-':return a - b;
        case '*':return a * b;
        case '/':return a / b;
        default:return -1;
    }
}
int main() {
    s[0] = '0';
    scanf("%s",s + 1);
    str();
    printf("%d\n",solve(1,strlen(s) - 1));
    return 0;
}
