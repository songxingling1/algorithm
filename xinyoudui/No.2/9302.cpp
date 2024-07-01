#include <bits/stdc++.h>
using namespace std;
int main() {
    int y1,m1,d1,y2,m2,d2,y3,m3,d3;
    scanf("%d%d%d",&y1,&m1,&d1);
    scanf("%d%d%d",&y2,&m2,&d2);
    scanf("%d%d%d",&y3,&m3,&d3);
    if(y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        swap(y1,y2);
        swap(m1,m2);
        swap(d1,d2);
    }
    if(y3 < y1 || y3 > y2) {
        printf("No\n");
    } else if((y3 == y1 && m3 < m1) || (y3 == y2 && m3 > m2)) {
        printf("No\n");
    } else if((y3 == y1 && m3 == m1 && d3 < d1) || (y3 == y2 && m3 == m2 && d3 > d2)) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}