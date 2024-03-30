#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;
int n;
int arr[MAX_N + 5];
int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        arr[i] = i;
    }
    int printCnt = 0,maxNum,ind;
    stack<int> sta;
    bool flag;
    do {
        maxNum = 1;
        while (!sta.empty()) sta.pop();
        sta.push(0);
        flag = false;
        ind = 1;
        while(ind <= n) {
            if(sta.top() < arr[ind]) {
                if(maxNum > n) break;
                sta.push(maxNum);
                maxNum++;
            } else if(sta.top() == arr[ind]) {
                sta.pop();
                ind++;
                if(ind == n + 1) flag = true;
            } else {
                break;
            }
        }
        if(flag) {
            for(int i = 1;i <= n;i++) printf("%d",arr[i]);
            puts("");
            printCnt++;
        }
    } while(next_permutation(arr + 1,arr + 1 + n) && printCnt < 20);
    return 0;
}