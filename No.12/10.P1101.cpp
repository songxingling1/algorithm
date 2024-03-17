#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int n;
char words[MAX_N + 5][MAX_N + 5];
int vis[MAX_N + 5][MAX_N + 5];
int ans[MAX_N + 5][MAX_N + 5];
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const char match[] = "yizhong";
void getAns(int x, int y) {
    int flag;
    for (int k = 0; k < 8; k++) {
        flag = 1;
        for (int j = 0; match[j]; j++) {
            int newx = x + dx[k] * j, newy = y + dy[k] * j;
            if (match[j] == words[newx][newy]) {
                continue;
            }
            flag = 0;
            break;
        }
        if (flag == 1) {
            for (int j = 0; match[j]; j++) {
                int newx = x + dx[k] * j, newy = y + dy[k] * j;
                ans[newx][newy] = 1;
            }
        }
    }
}
void dfs(int x, int y) {
    if (words[x][y] == '\0' || vis[x][y])
        return;
    if (words[x][y] == 'y') {
        getAns(x, y);
    }
    vis[x][y] = 1;
    dfs(x + 1, y);
    dfs(x, y + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", words[i] + 1);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j])
                printf("%c", words[i][j]);
            else
                printf("*");
        }
        puts("");
    }
}