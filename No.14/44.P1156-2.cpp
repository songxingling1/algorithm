#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
struct Waste {
    int t,f,h;
} arr[MAX_N + 5];
int dp[4000];
int main() {
    int D,G;
    scanf("%d%d",&D,&G);
    for(int i = 1;i <= G;i++) {
        scanf("%d%d%d",&arr[i].t,&arr[i].f,&arr[i].h);
    }
    sort(arr + 1,arr + 1 + G,[](const Waste &i,const Waste &j)->bool{
        return i.t < j.t;
    });
    int cnt = 10;
    for(int i = 1;i <= G;i++) {
        for(int j = cnt;j >= arr[i].t;j--) {
            if(dp[j] + arr[i].h >= D) {
                printf("%d\n",arr[i].t);
                return 0;
            }
            dp[j + arr[i].f] = max(dp[j + arr[i].f],dp[j]);
            dp[j] += arr[i].h;
        }
        if(cnt >= arr[i].t) cnt += arr[i].f;
    }
    printf("%d\n",cnt);
    return 0;
}