#include <bits/stdc++.h>
using namespace std;
class UnionSet {
public:
    UnionSet(int n):fa(n + 5),code(n + 5,0) {
        for(int i = 1;i <= n;i++) fa[i] = i;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        int ans = find(fa[x]);
        code[x] = (code[x] + code[fa[x]]) % 3;
        return fa[x] = ans;
    }
    void merge(int i,int j) {
        int a = find(i),b = find(j);
        if(a == b) return;
        fa[a] = b;
        code[a] = (4 - code[i] + code[j]) % 3;
    }
    vector<int> fa,code;
};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    UnionSet s(n);
    int a,b,c,bb,cc;
    while(m--) {
        scanf("%d%d%d",&a,&b,&c);
        if(a == 1) {
            s.merge(b,c);
        } else {
            bb = s.find(b);
            cc = s.find(c);
            if(bb != cc) {
                printf("Unknown\n");
                continue;
            }
            if((s.code[b] - s.code[c] + 3) % 3 == 0) {
                printf("Tie\n");
            } else if((s.code[b] - s.code[c] + 3) % 3 == 1) {
                printf("Win\n");
            } else {
                printf("Loss\n");
            }
        }
    }
    return 0;
}