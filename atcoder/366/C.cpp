#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int arr[1000005];
void add(int x) {
    arr[x]++;
    cnt += (arr[x] == 1); 
}
void del(int x) {
    arr[x]--;
    cnt -= (arr[x] == 0);
}
int main() {
    int q;
    scanf("%d",&q);
    int op,x;
    for(int i = 1;i <= q;i++) {
        scanf("%d",&op);
        if(op == 1) {
            scanf("%d",&x);
            add(x);
        } else if (op == 2) {
            scanf("%d", &x);
            del(x);
        } else {
            printf("%d\n",cnt);
        }
    }
    return 0;
}