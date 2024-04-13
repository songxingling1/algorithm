#include <bits/stdc++.h>
#define MAX_N 2500
using namespace std;
struct Dat { // NOTE : 奶牛和防晒霜的数据结构体
    int a,b;
} cow[MAX_N + 5],fang[MAX_N + 5];
int main() {
    int C,L;
    scanf("%d%d",&C,&L);
    for(int i = 1;i <= C;i++) {
        scanf("%d%d",&cow[i].a,&cow[i].b);
    }
    for(int i = 1;i <= L;i++) {
        scanf("%d%d",&fang[i].a,&fang[i].b);
    }
    sort(cow + 1,cow + 1 + C,[](const Dat &i,const Dat &j)->bool{ // NOTE : 排序
        if(i.b != j.b) return i.b < j.b;
        return i.a < j.a;
    });
    sort(fang + 1,fang + 1 + L,[](const Dat &i,const Dat &j)->bool{ // NOTE : 排序
        if(i.a != j.a) return i.a < j.a;
        return i.b < j.b;
    });
    int ans = 0;
    for(int i = 1;i <= C;i++) { // NOTE : 涂抹防晒霜
        int flag = 0;
        for(int j = 1;j <= L;j++) { // NOTE : 便利所有防晒霜
            if(fang[j].b == 0) continue;
            if(fang[j].a >= cow[i].a && fang[j].a <= cow[i].b) { // NOTE :  是否可用
                flag = 1;
                fang[j].b--;
                break;
            }
        }
        ans += flag;
    }
    printf("%d\n",ans);
    return 0;
}