#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,r;
    scanf("%d%d%d",&a,&b,&r);
    int n = a / r / 2,m = b / r / 2;
    if(n == 0 || m == 0) {
        printf("Bob win\n");
        return 0;
    } else {
        printf("Alice win\n");
    }
    return 0;
}