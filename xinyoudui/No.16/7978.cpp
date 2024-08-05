#include <bits/stdc++.h>
using namespace std;
int ind[15] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int main() {
    int n;
    scanf("%d", &n);
    int sum = 1, cnt = 1;
    while (n > sum) {
        cnt++;
        n -= sum;
        sum *= cnt;
    }
    while (--n) {
        next_permutation(ind, ind + cnt);
    }
    for (int i = 0; i < cnt; i++) {
        printf("%d ", ind[i]);
    }
    puts("");
    return 0;
}