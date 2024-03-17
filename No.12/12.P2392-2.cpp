// 状态压缩枚举
#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;
int s[5];          // 每一个科目的题目个数
int t[5][MAX_N + 5];          // t[i][j] : 第i个科目的第j道题的完成时间
int sum[5] = { 0 };          // sum[i] : i科目所有题目的最长总消耗时间
unordered_map<int, int> ind;
int solve(int num /*学科编号*/) {
    // TODO : 获取num学科的最小做题时间
    int code = 1 << s[num];
    int j, left = 0, right = 0, ans = 0x3f3f3f3f;
    for (int i /*二进制：0右脑，1左脑*/ = 0; i < code; i++) {
        j = i;
        while (j) {
            left += t[num][ind[j & -j]];
            j -= j & -j;
        }
        right = sum[num] - left;
        ans = min(ans, max(left, right));
        left = 0;
    }
    return ans;
}
int main() {
    scanf("%d%d%d%d", &s[1], &s[2], &s[3], &s[4]);
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= s[i]; j++) {
            scanf("%d", &t[i][j]);
            sum[i] += t[i][j];
        }
    }
    for (int i = 1, k = 1; i <= MAX_N; i++, k *= 2) {
        ind[k] = i;
    }
    int total = 0;
    for (int i = 1; i <= 4; i++) {
        total += solve(i);
    }
    printf("%d\n", total);
    return 0;
}