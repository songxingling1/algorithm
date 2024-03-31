#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
typedef long long ll;
char s[MAX_N + 5];
ll m[MAX_N + 5] = {0};
ll judge(ll pos) {
    if(s[pos] == '-' && (s[pos - 1] == '(' || pos == 1 || (!isdigit(s[pos - 1]))) && s[pos - 1] != ')') return 4;
    char c = s[pos];
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 4;
}
ll qpow(ll a,ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void str() {
    ll isK = 0;
    ll size = strlen(s);
    for(ll i = 1;i < size;i++) {
        if(s[i] == '(') isK += 100;
        m[i] = judge(i) + isK;
        if(s[i] == ')' && isK != 0) isK -= 100;
    }
}
ll isNUm(ll begin,ll end) {
    ll ans = 0;
    ll dr = 0;
    if(!(isdigit(s[begin]) || s[begin] == '-') && s[begin] != '(' && s[begin] != ')') return -1;
    if(s[begin] == '-') dr = -1;
    if(isdigit(s[begin])) ans = (ll)s[begin] - '0';
    for(ll i = begin + 1;i <= end;i++) {
        if(s[i] == '(' || s[i] == ')') continue;
        if(!isdigit(s[i]) && !(dr == 0 && s[i] == '-')) return -1;
        if(dr == 0 && s[i] == '-') dr = -1;
        else ans = (ll)ans * 10 + (s[i] - '0');
    }
    if(dr == -1) ans *= -1;
    return ans;
}
ll solve(int begin,int end) {
    ll nums = isNUm(begin,end);
    if(nums != -1) return nums;
    ll pos = 0,num = 0x3f3f3f3f;
    for(ll i = begin;i <= end;i++) {
        if(s[i] == '(' || s[i] == ')') continue;
        if(num >= m[i]) {
            num = m[i];
            pos = i;
        }
    }
    ll a = solve(begin,pos - 1);
    ll b = solve(pos + 1,end);
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