#include <bits/stdc++.h>
using namespace std;
class UnionSet {
public:
    UnionSet(int n):fa(n + 5) {
        for(int i = 0;i <= n;i++) fa[i] = i;
    }
    int find(int x) {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }
    void merge(int a,int b) {
        fa[find(a)] = fa[find(b)];
    }
    vector<int> fa;
};
struct dat {
    int a,b;
};
void solve() {
    int n;
    scanf("%d",&n);
    unordered_map<int,int> map;
    vector<dat> v1,v2;
    int e,cnt = 0;
    dat tmp;
    for(int i = 1;i <= n;i++) {
        scanf("%d%d%d",&tmp.a,&tmp.b,&e);
        if(e == 1) {
            if(map.find(tmp.a) == map.end()) map[tmp.a] = ++cnt;
            if(map.find(tmp.b) == map.end()) map[tmp.b] = ++cnt;
            v1.push_back(tmp);
        }
        else {
            if(map.find(tmp.a) == map.end()) map[tmp.a] = ++cnt;
            if(map.find(tmp.b) == map.end()) map[tmp.b] = ++cnt;
            v2.push_back(tmp);
        }
    }
    UnionSet u(cnt);
    for(dat i:v1) {
        u.merge(map[i.a],map[i.b]);
    }
    bool ok = true;
    for(dat i:v2) {
        if(u.find(map[i.a]) == u.find(map[i.b])) {
            ok = false;
            break;
        }
    }
    printf("%s\n",ok ? "YES" : "NO");
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        solve();
    }
    return 0;
}