#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int xx[MAX_N + 5],yy[MAX_N + 5];
int main() {
    int X,Y,contx = 0,conty = 0,n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%d%d",&xx[i],&yy[i]);
    }
    sort(xx,xx + n);
    for(int i = 0;i < n;i++) xx[i] -= i;
    sort(xx,xx + n);
    sort(yy,yy + n);
    X = xx[n / 2];
    Y = yy[n / 2];
    for(int i = 0;i < n;i++) contx += abs(xx[i] - X);
    for(int i = 0;i < n;i++) conty += abs(yy[i] - Y);
    printf("%d\n",contx + conty);
    return 0;
}