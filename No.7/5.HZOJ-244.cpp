#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;
struct Point {
    int x,y;
} arr[MAX_N + 5],tmp[MAX_N + 5];
int c,n;
bool checkKid(int a,int l,int r) {
    for(int i = l;i <= r;i++) {
        tmp[i] = arr[i];
    }
    sort(tmp + l,tmp + r + 1,[](Point i,Point j)->bool{
        return i.y > j.y;
    });
    int j = l;
    for(int i = l;i <= r;i++) {
        while(tmp[j].y - tmp[i].y >= a) j++;
        if(i - j + 1 < c) continue;
        return true;
    }
    return false;
}
bool check(int a) {
    int j = 1;
    for(int i = 1;i <= n;i++) {
        while(arr[i].x - arr[j].x >= a) j++;
        if(i - j + 1 < c) continue;
        if(checkKid(a,j,i)) return true;
    }
    return false;
}
int solve() {
    int l = 1,r = 10010,mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main() {
    scanf("%d%d",&c,&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&arr[i].x,&arr[i].y);
    }
    sort(arr + 1,arr + 1 + n,[](Point i,Point j)->bool{
        if(i.x != j.x) return i.x < j.x;
        return i.y > j.y;
    });
    printf("%d\n",solve());
    return 0;
}