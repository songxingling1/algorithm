#include <bits/stdc++.h>
#define MOD1 10000007
#define MOD2 10000009
#define BASE 131
using namespace std;
typedef long long ll;
char s[1505];
pair<ll,ll> ha[10005];
pair<ll,ll> hash_func(const char *s) {
    ll h1 = 0,h2 = 0;
    for(int i = 0;s[i];i++) {
        h1 = (h1 * BASE + (ll)s[i]) % MOD1;
        h2 = (h2 * BASE + (ll)s[i]) % MOD2;
    }
    return make_pair(h1,h2);
}
int main() {
    int n,ans = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%s",s);
        ha[i] = hash_func(s);
    }
    sort(ha + 1,ha + 1 + n);
    for(int i = 1;i <= n;i++) {
        if(ha[i].first != ha[i - 1].first || ha[i].second != ha[i - 1].second) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}