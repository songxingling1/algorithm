#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
struct Node { // NOTE : 神经元
    int c,u,status; // status : 0001输入层  0010输出层
} nod[MAX_N + 5];
struct Edge { // NOTE : 有向带权边
    Edge(int t,int w):to(t),weight(w) {}
    int to,weight;
};
vector<Edge> edg[MAX_N + 5]; // NOTE ： 边
int rudu[MAX_N + 5] = {0}; // NOTE : 入度
int main() {
    int n,p;
    scanf("%d%d",&n,&p); // NOTE : 输入
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&nod[i].c,&nod[i].u);
        nod[i].status = 0;
    }
    for(int i = 1,a,b,c;i <= p;i++) {
        scanf("%d%d%d",&a,&b,&c);
        edg[a].emplace_back(b,c);
        rudu[b]++;
    }
    queue<int> que;
    for(int i = 1;i <= n;i++) { // NOTE : 找输入层和输出层
        if(rudu[i] == 0) {
            nod[i].status += 1;
            nod[i].c += nod[i].u;
        }
        if(edg[i].size() == 0) nod[i].status += 2;
        if(nod[i].status & 1) que.push(i);
    }
    int x;
    while(!que.empty()) { // NOTE : 拓扑排序
        x = que.front();
        que.pop();
        nod[x].c -= nod[x].u;
        for(Edge i:edg[x]) {
            if(nod[x].c > 0) nod[i.to].c += i.weight * nod[x].c;
            rudu[i.to]--;
            if(rudu[i.to] == 0) que.push(i.to);
        }
    }
    int flag = 1;
    for(int i = 1;i <= n;i++) { // NOTE : 输出
        if(!(nod[i].status & 2)) continue;
        if(nod[i].c <= 0) continue;
        printf("%d %d\n",i,nod[i].c);
        flag = 0;
    }
    if(flag) printf("NULL\n");
    return 0;
}