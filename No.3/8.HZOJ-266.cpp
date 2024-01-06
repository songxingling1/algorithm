#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
char s[MAX_N + 5];//字符串
long long m[MAX_N + 5] = {0}; //权
long long judge(long long pos) { //判断运算符层级
    if(s[pos] == '-' && (s[pos - 1] == '(' || pos == 1 || (!isdigit(s[pos - 1]))) && s[pos - 1] != ')') return 4;
    char c = s[pos];
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 4;
}
long long qpow(long long a,long long b) { //快速幂
    long long ans = 1;
    while(b) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void str() { //计算权值
    long long isK = 0;
    long long size = strlen(s);
    /**********************   第一部分：遍历字符串   ***************************/
    for(long long i = 1;i < size;i++) {
        if(s[i] == '(') isK += 100; //bug1:权值没有考虑到有多重括号的式子 (isk = true)
        m[i] = judge(i) + isK;
        if(s[i] == ')' && isK != 0) isK -= 100;//bug1:权值没有考虑到有多重括号的式子 (isk = false)
    }
}
long long isNumber(long long begin,long long end) { //判断是否为数字：不是返回-1             是返回数字的值
    long long ans = 0;
    long long dr = 0;
    if(!(isdigit(s[begin]) || s[begin] == '-') && s[begin] != '(' && s[begin] != ')') return -1;
    if(s[begin] == '-') dr = -1;
    if(isdigit(s[begin])) ans = (long long)s[begin] - '0'; //bug4:没有考虑到第一位是数字的情况 (delete)
    for(long long i = begin + 1;i <= end;i++) {
        if(s[i] == '(' || s[i] == ')') continue;
        if(!isdigit(s[i]) && !(dr == 0 && s[i] == '-')) return -1; //bug3:没有考虑到'-'不在第一位的情况 (if(!isdigit(s[i])) return -1;)
        if(dr == 0 && s[i] == '-') dr = -1;
        else ans = (long long)ans * 10 + (s[i] - '0');
    }
    if(dr == -1) ans *= -1;
    return ans;
}
long long solve(int __begin,int __end) { //主要解决方案
    /*******************   边界   ******************/
    long long nums = isNumber(__begin,__end);
    if(nums != -1) return nums;
    /**********************   第一部分：遍历字符串   ***************************/
    //在79行执行过了！！！
    /***************************   第二部分：取最小值    ***************************************/
    long long pos = 0,num = 0x3f3f3f3f;
    for(long long i = __begin;i <= __end;i++) {
        if(s[i] == '(' || s[i] == ')') continue;
        if(num >= m[i]) { //bug2:没有从左往右计算 (num > m[i])
            num = m[i];
            pos = i;
        }
    }
    /*********************    第三部分：分割    ***********************/
    long long a = solve(__begin,pos - 1);
    long long b = solve(pos + 1,__end);
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
    printf("%lld\n",solve(1,strlen(s) - 1));
    return 0;
}
