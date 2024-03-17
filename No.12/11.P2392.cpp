// 普通深搜
#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;
int s[5];          // s1，s2，s3，s4，s5
int ans;          // 答案变量
vector<vector<int>> n(5, vector<int>(MAX_N + 5));
// TODO(1) : t[i][j] (n[i][j]) 第i学科的第j道题所花的时间
void dfs(int cnt /*正在做第几个题*/,
         int num /*学科*/,
         int left /*左脑花费的时间*/,
         int right /*右脑花费的时间*/) {
    if (cnt == s[num] + 1) {
        ans = min(ans, max(left, right));
        return;
    }
    // TODO(2) : 用左脑思考的情况
    left += n[num][cnt];
    dfs(cnt + 1, num, left, right);
    left -= n[num][cnt];
    // TODO(3) : 用右脑思考的情况
    right += n[num][cnt];
    dfs(cnt + 1, num, left, right);
    right -= n[num][cnt];
}
int main() {
    scanf("%d%d%d%d", &s[1], &s[2], &s[3], &s[4]);
    // TODO(4) : 输入四个科目的题目数量
    for (int i = 1; i <= s[1]; i++) {
        scanf("%d", &n[1][i]);
    }
    for (int i = 1; i <= s[2]; i++) {
        scanf("%d", &n[2][i]);
    }
    for (int i = 1; i <= s[3]; i++) {
        scanf("%d", &n[3][i]);
    }
    for (int i = 1; i <= s[4]; i++) {
        scanf("%d", &n[4][i]);
    }
    int total = 0;
    for (int i = 1; i <= 4; i++) {          //获取每一科需要的时间
        ans = 0x3f3f3f3f;
        dfs(1, i, 0, 0);          //获取这一科的时间
        total += ans;
    }
    printf("%d\n", total);
    return 0;
}