#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,step;
    scanf("%d%d%d",&a,&b,&step);
    if(step < abs(a + b)) {
        printf("No\n");
    } else if((step - abs(a + b)) % 2 != 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}