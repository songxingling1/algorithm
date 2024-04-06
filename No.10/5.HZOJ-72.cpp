#include <bits/stdc++.h>
#define elif else if
using namespace std;
class UnionSet {
public:
    UnionSet(int n):fa(n + 5),code(n + 5,0) {
        for(int i = 0;i <= n;i++) fa[i] = i;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        int ans = find(fa[x]);
        code[x] = (code[x] + code[fa[x]]) % 3;
        return fa[x] = ans;
    }
    void merge(int a,int b) {
        int aa = find(a),bb = find(b);
        if(aa == bb) return;
        code[aa] = (5 - code[a] + code[b]) % 3;
        fa[aa] = bb;
    }
    vector<int> fa,code;
};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b,c;
    UnionSet u(n);
    while(m--) {
        scanf("%d%d%d",&a,&b,&c);
        if(a == 1) {
            u.merge(b,c);
        } else {
            if(u.find(b) != u.find(c)) {
                printf("Unknown\n");
            } elif ((u.code[b] - u.code[c] + 3) % 3 == 0) {
                printf("Tie\n");
            } elif ((u.code[b] - u.code[c] + 3) % 3 == 1) {
                printf("Loss\n");
            } else {
                printf("Win\n");
            }
        }
    }
    return 0;
}