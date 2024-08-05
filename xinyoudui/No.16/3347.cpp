#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
int vis[1005];
int len;
int isPrime(int x) {
    int xx = sqrt(x);
    for (int i = 2; i <= xx; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
void generic() {
    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i)) prime.push_back(i);
    }
    len = prime.size();
}
int bfs(int s, int t) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> que;
    que.push({s, 0});
    vis[s] = 1;
    pair<int, int> tmp;
    while (!que.empty()) {
        tmp = que.front();
        que.pop();
        if (tmp.first == t) return tmp.second;
        for (int i = 0; prime[i] < tmp.first && i < len;
             i++) {
            if (tmp.first % prime[i] != 0) continue;
            int ind = tmp.first + prime[i];
            if (ind <= t && !vis[ind]) {
                que.push({ind, tmp.second + 1});
                vis[ind] = 1;
            }
        }
    }
    return -1;
}
int main() {
    int T, s, t;
    scanf("%d", &T);
    generic();
    for (int i = 1; i <= T; i++) {
        scanf("%d%d", &s, &t);
        printf("Case %d: %d\n", i, bfs(s, t));
    }
    return 0;
}