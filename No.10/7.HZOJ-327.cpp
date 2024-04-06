#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
class UnionSet {
public:
    UnionSet(int n):fa(n + 5),code(n + 5,0) {
        for(int i = 0;i <= n;i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if(fa[x] == x) return x;
        int ans = find(fa[x]);
        code[x] = (code[x] + code[fa[x]]) % 2;
        return fa[x] = ans;
    }
    void merge(int a,int b) {
        int aa = find(a),bb = find(b);
        if(aa == bb) return;
        code[aa] = (code[a] + code[b] + 1) % 2;
        fa[aa] = bb;
    }
    vector<int> fa,code;
};
struct dat {int a,b,c;} arr[MAX_N + 5];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++) scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c); // NOTE : 输入
    sort(arr + 1,arr + m + 1,[](const dat &i,const dat &j)->bool{
        return i.c > j.c;
    }); // NOTE : 排序
    UnionSet u(n);
    int ans = 0; // NOTE : 处理罪犯对
    for(int i = 1;i <= m;i++) {
        if(u.find(arr[i].a) == u.find(arr[i].b) && (u.code[arr[i].a] + u.code[arr[i].b]) % 2 == 0) {
            ans = arr[i].c;
            break;
        }
        u.merge(arr[i].a,arr[i].b);
    }
    printf("%d\n",ans);
    return 0;
}