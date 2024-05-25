#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
struct Waste {
    int t,f,h;
} arr[MAX_N + 5];
int dp[2 * MAX_N + 5];
int main() {
    int D,G;
    scanf("%d%d",&D,&G);
    for(int i = 1;i <= G;i++) {
        scanf("%d%d%d",&arr[i].t,&arr[i].f,&arr[i].h);
    }
    sort(arr + 1,arr + 1 + G,[](const Waste &i,const Waste &j)->bool{
        return i.t < j.t;
    });
    dp[0] = 10;
    for(int i = 1;i <= G;i++) {
        for(int j = D;j >= 0;j--) {
            if(dp[j] < arr[i].t) {
                continue;
            }
            if(j + arr[i].h >= D) {
                printf("%d\n",arr[i].t);
                return 0;
            }
            dp[j + arr[i].h] = max(dp[j + arr[i].h],dp[j]);
            dp[j] += arr[i].f;
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}